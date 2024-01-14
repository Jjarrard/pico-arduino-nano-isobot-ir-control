# Pico w + Arduino Nano i-Sobot
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

**Commands**
forward                                   0
backward                                  1
sideright                                 2
sideleft                                  3
fleft                                     4
fright                                    5
bleft                                     6
bright                                    7
fclockwise                                8
fcounter                                  9
bclockwise                                10
bcounter                                  11
headleft                                  12
headright                                 13
leanforward                               14
leanback                                  15
lpunch                                    16
r12                                       17
lchop                                     18
sidechopl                                 19
combopunch                                20
rpunch                                    21
rchop                                     22
l12                                       23
sidechopr                                 24
lbackhand                                 25
doublechop                                26
doublebackhand                            27
slapping                                  28
rbackhand                                 29
upperchop                                 30
roundhousel                               31
roundhouser                               32
forwardkickl                              33
forwardkickr                              34
sidekickl                                 35
roundhouselr                              36
forwardkicklr                             37
combokick                                 38
sidekickr                                 39
backkickl                                 40
backkickr                                 41
highkickl                                 42
highkickr                                 43
splits1                                   44
guardl                                    45
guardr                                    46
doubleguard1                              47
doubleguard2                              48
dodgel                                    49
dodger                                    50
duck                                      51
swayback                                  52
upblock                                   53
splits2                                   54
comboblock                                55
zero                                      56
homeposition                              57
soundoff                                  58
affirm                                    59
disagree                                  60
goodmorning                               61
greet1                                    62
greet2                                    63
greet3                                    64
greet4                                    65
bye1                                      66
bye2                                      67
bye3                                      68
bye4                                      69
bye5                                      70
respect                                   71
thanks1                                   72
thanks2                                   73
love1                                     74
love2                                     75
love3                                     76
standupfront                              77
standupback                               78
excited1                                  79
excited2                                  80
excited3                                  81
excited4                                  82
party                                     83
amazed                                    84
regret1                                   85
regret2                                   86
regret3                                   87
worry                                     88
pain1                                     89
pain2                                     90
beg1                                      91
beg2                                      92
merry                                     93
hilarious                                 94
hidenseek                                 95
youlike                                   96
mystery5                                  97
tipsy                                     98
tickleme                                  99
tiredfeet                                 100
needabreak                                101
wave1                                     102
wave2                                     103
applause                                  104
mystery6                                  105
toosexy                                   106
clink                                     107
relax                                     108
soccer1                                   109
soccer2                                   110
soccer3                                   111
lift                                      112
countonme                                 113
articulation                              114
showoff1                                  115
showoff2                                  116
showoff3                                  117
showoff4                                  118
cominthrough                              119
catch                                     120
randomperformance2                        121
western                                   122
giantrobot                                123
tropicaldance                             124
randomanimal                              125
randomperformance1                        126
airguitar                                 127
airdrum                                   128
exercises                                 129
headstandexercises                        130
forwardsomersault                         131
mystery4                                  132
mystery3                                  133
mystery2                                  134
mystery1                                  135
pose3                                     136
pose2                                     137
pose1                                     138
