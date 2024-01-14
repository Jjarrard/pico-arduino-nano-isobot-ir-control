# pico-duinonano-i-sobot
Control your Tomy i-Sobot over wifi using a pico W and a 16MHz arduino nano

Only rudimentary currently, manually typing in the command number and pressing the button.

Library files borrowed from Miles Moody, thanks for doing the hard work!

**Getting started**

1. Load MicroPython onto your Pico W.

2. Change the wifi settings in main.py (main.py should run on boot, google if not).

3. Upload main.py

4. Add Isobot library to arduino editor.

5. Send the ino file to the arduino using the settings below (remember it needs to be a 16MHz Arduino).

![image](https://github.com/Jjarrard/pico-duinonano-i-sobot/assets/15104602/ebbdba67-ace4-4200-8cd8-49e09bdc92f9)

6. Plug in an IR LED into D5 and GND (For testing I even used a normal clear red one).

7. Plug a jumper between the Pico W TX pin and the Arduino RX pin.

8. Watch the Thonny (Pico) shell for the IP you'll need to visit to send the commands.

