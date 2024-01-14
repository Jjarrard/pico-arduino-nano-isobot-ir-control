#include "Arduino.h"
#include "Isobot.h"

//As you can see, the below is borrowed but I cut it down to do send commands only

//Isobot IR decoder and Controller
//Written by Miles Moody
//Isobot IR protocol works as follows
//carrier freq of about 38khz
//header pulse of 2550 micros high
//22 data bits=4 for channel number, 18 for button number
//highs carry no info and are 550 micros each
//lows are logic 0 if 550 micros, logic 1 if 1050 micros
//at end of stream or in between, 205 millis low
//NOTE: my ir reciever pin goes low when it detects high signal
//      and stays high when nothing is being recieved
//      that could cause some confusion

//-------------------info about bits-------------------------------
#define totallength 22            //number of highs=bits 4 channel +18 command
#define channelstart 0
#define commandstart 4       //bit where command starts
#define channellength  4
#define commandlength  18
//---------determined empirically--------------
#define headerlower 2300     //lower limit
#define headernom 2550       //nominal
#define headerupper 2800     //upper limit
#define zerolower 300
#define zeronom 380          //nominal
#define zeroupper 650
#define onelower 800
#define onenom 850          //nominal
#define oneupper 1100
#define highnom 630

bool bit2[22]={};

//Constructors
Isobot::Isobot(int txpin){
   pinMode(txpin, OUTPUT);
   TXpin=txpin;
}
Isobot::Isobot(int txpin, int rxpin){
   pinMode(txpin, OUTPUT);
   pinMode(rxpin, INPUT);
   TXpin=txpin;
   RXpin=rxpin;
}

//functions
void Isobot::oscWrite(int time){
for(int i = 0; i < (time / 28) - 1; i++){          //prescaler at 28 for 16mhz, 52 at 8mhz, ? for 20mhz
   digitalWrite(TXpin, HIGH);
   delayMicroseconds(13);
   digitalWrite(TXpin, LOW);
   delayMicroseconds(13);
 }
}

unsigned long Isobot::power2(int power){    //gives 2 to the int(power)
   unsigned long integer=1;                //apparently both bitshifting and pow functions had problems
 for (int i=0; i<power; i++){              //so I made my own
   integer*=2;
 }
 return integer;
}

void Isobot::buttonwrite(unsigned long integer, int numoftimes){      //same as above but repeats numoftimes
   Serial.println("buttonwrite running");

 ItoB(integer, 22);                                      
 for (int n=0;n<numoftimes;n++){
   oscWrite(headernom);
   for(int i=0;i<totallength;i++){
       if (bit2[i]==0)delayMicroseconds(zeronom);
       else delayMicroseconds(onenom);
       oscWrite(highnom);
   }
 delay(205);
 }
}

void Isobot::ItoB(unsigned long integer, int length){                //needs bit2[length]
 for (int i=0; i<length; i++){
   if ((integer / power2(length-1-i))==1){
     integer-=power2(length-1-i);
     bit2[i]=1;
   }
   else bit2[i]=0;
 }
}


