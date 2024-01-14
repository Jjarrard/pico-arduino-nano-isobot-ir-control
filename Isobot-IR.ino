#include <Isobot.h>
#include <SoftwareSerial.h>

Isobot bot(5);      //IR transmitter hooked to D5
unsigned long time1, time2;
String data0;
String data1; 

unsigned long Code[] = {
  forward,                                  // 0
backward,                                 // 1
sideright,                                // 2
sideleft,                                 // 3
fleft,                                    // 4
fright,                                   // 5
bleft,                                    // 6
bright,                                   // 7
fclockwise,                                // 8
fcounter,                                 // 9
bclockwise,                               // 10
bcounter,                                 // 11
headleft,                                 // 12
headright,                                // 13
leanforward,                              // 14
leanback,                                 // 15
lpunch,                                   // 16
r12,                                      // 17
lchop,                                    // 18
sidechopl,                                // 19
combopunch,                               // 20
rpunch,                                   // 21
rchop,                                    // 22
l12,                                      // 23
sidechopr,                                // 24
lbackhand,                                // 25
doublechop,                               // 26
doublebackhand,                           // 27
slapping,                                 // 28
rbackhand,                                // 29
upperchop,                                // 30
roundhousel,                              // 31
roundhouser,                              // 32
forwardkickl,                             // 33
forwardkickr,                             // 34
sidekickl,                                // 35
roundhouselr,                             // 36
forwardkicklr,                            // 37
combokick,                                // 38
sidekickr,                                // 39
backkickl,                                // 40
backkickr,                                // 41
highkickl,                                // 42
highkickr,                                // 43
splits1,                                  // 44
guardl,                                   // 45
guardr,                                   // 46
doubleguard1,                             // 47
doubleguard2,                             // 48
dodgel,                                   // 49
dodger,                                   // 50
duck,                                     // 51
swayback,                                 // 52
upblock,                                  // 53
splits2,                                  // 54
comboblock,                               // 55
zero,                                     // 56
homeposition,                             // 57
soundoff,                                 // 58
affirm,                                   // 59
disagree,                                 // 60
goodmorning,                              // 61
greet1,                                   // 62
greet2,                                   // 63
greet3,                                   // 64
greet4,                                   // 65
bye1,                                     // 66
bye2,                                     // 67
bye3,                                     // 68
bye4,                                     // 69
bye5,                                     // 70
respect,                                  // 71
thanks1,                                  // 72
thanks2,                                  // 73
love1,                                    // 74
love2,                                    // 75
love3,                                    // 76
standupfront,                             // 77
standupback,                              // 78
excited1,                                 // 79
excited2,                                 // 80
excited3,                                 // 81
excited4,                                 // 82
party,                                    // 83
amazed,                                   // 84
regret1,                                  // 85
regret2,                                  // 86
regret3,                                  // 87
worry,                                    // 88
pain1,                                    // 89
pain2,                                    // 90
beg1,                                     // 91
beg2,                                     // 92
merry,                                    // 93
hilarious,                                // 94
hidenseek,                                // 95
youlike,                                  // 96
mystery5,                                 // 97
tipsy,                                    // 98
tickleme,                                 // 99
tiredfeet,                                // 100
needabreak,                               // 101
wave1,                                    // 102
wave2,                                    // 103
applause,                                 // 104
mystery6,                                 // 105
toosexy,                                  // 106
clink,                                    // 107
relax,                                    // 108
soccer1,                                  // 109
soccer2,                                  // 110
soccer3,                                  // 111
lift,                                     // 112
countonme,                                // 113
articulation,                             // 114
showoff1,                                 // 115
showoff2,                                 // 116
showoff3,                                 // 117
showoff4,                                 // 118
cominthrough,                             // 119
catch,                                    // 120
randomperformance2,                        // 121
western,                                  // 122
giantrobot,                               // 123
tropicaldance,                            // 124
randomanimal,                             // 125
randomperformance1,                        // 126
airguitar,                                // 127
airdrum,                                  // 128
exercises,                                // 129
headstandexercises,                       // 130
forwardsomersault,                        // 131
mystery4,                                 // 132
mystery3,                                 // 133
mystery2,                                 // 134
mystery1,                                 // 135
pose3,                                    // 136
pose2,                                    // 137
pose1 };                                  // 138


SoftwareSerial mySerial(3, 4); // RX, TX 
 

void setup() {
  pinMode(0,INPUT); //You only need to plug in your pico tx into the arduino nano rx pin.
  
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println(F("I-Sobot serial control v1.0. Please type command the push enter"));

}

void loop() {
serialCommand();
}

void serialCommand(){

  // Check if there is data available on either the Serial or mySerial interfaces
 if (Serial.available()> 0 || mySerial.available())
 {
      // If there is data available on the Serial interface
  if(Serial.available()){
          // Read the data from the Serial interface into data1
   data1 = Serial.readString();
         // Convert the data to an integer
byte i = atoi(data1.c_str());

  // If the integer is less than or equal to 11
  if(i <= 11){
  // Print and write the corresponding code from the Code array to the bot five times
    for(byte k = 0; k < 5; k++){
        Serial.println(Code[i]);
        bot.buttonwrite(Code[i],3);         
    }
  }else{
      // If the integer is greater than 11, print and write the code once
     Serial.println(Code[i]);
     bot.buttonwrite(Code[i],3);        
    }
  }
  // If there is data available on the mySerial interface
  if(mySerial.available()){
    // Read the data from the mySerial interface into data0
    data0 = mySerial.readString();
    // Convert the data to an integer
    byte ir = atoi(data0.c_str()); 
    // If the integer is less than or equal to 11
    if(ir <= 11){
      // Print and write the corresponding code from the Code array to the bot five times
      for(byte k = 0; k < 5; k++){
        Serial.println(Code[ir]);
        bot.buttonwrite(Code[ir],3);         
    }
  }else{
      // If the integer is greater than 11, print and write the code once
        Serial.println(Code[ir]);
        bot.buttonwrite(Code[ir],3);          
    }
  }
        
 }  
}
