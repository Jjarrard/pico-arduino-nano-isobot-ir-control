import time
import machine
from machine import Pin
import network
import socket

led = Pin(15, Pin.OUT)
uart = machine.UART(0, baudrate=9600)

ssid = 'WIFI SSID'
password = 'YOUR WIFI PASS'

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(ssid, password)

html = """<!DOCTYPE html>
<html>
    <head> <title>Pico W</title> </head>
    <body> 
        <h1>Pico W</h1>
        <p>Hello world</p>
        <form action="/send">
            <input type="number" name="number">
            <input type="submit" value="Send">
        </form>
    </body>
</html>
"""

max_wait = 10
while max_wait > 0:
    if wlan.status() < 0 or wlan.status() >= 3:
        break
    max_wait -= 1
    print('waiting for connection...')
    time.sleep(1)

if wlan.status() != 3:
    raise RuntimeError('network connection failed')
else:
    print('connected')
    status = wlan.ifconfig()
    print( 'ip = ' + status[0] )

addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]

s = socket.socket()
s.bind(addr)
s.listen(1)

print('listening on', addr)

# Listen for connections
while True:
    try:
        cl, addr = s.accept()
        print('client connected from', addr)
        request = cl.recv(1024)
        print(request)

        if request:  # Add this line
            # Parse the request to get the number
            request_line = request.decode().split('\r\n')[0]
            method, path, _ = request_line.split(' ')
            if method == 'GET' and path.startswith('/send'):
                query = path.split('?', 1)[-1]
                params = dict(param.split('=') for param in query.split('&'))
                number = params.get('number')
                if number:
                    number = int(number)
                    print('Number from form:', number)
                    uart.write(str(number).encode())

        response = html

        cl.send('HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n')
        cl.send(response)
        cl.close()

    except OSError as e:
        cl.close()
        print('connection closed')
