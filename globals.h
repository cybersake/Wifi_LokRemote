#define BUILTIN_LED 38
#define MOTORIN1 40                   // 19 IN1 input of the DRV8871 motor driver board
#define MOTORIN2 39                   // 21 IN2 input of the DRV8871 motor driver board
#define PWMFREQ 15000                 // PWM frequency
#define LIGHT1 38                     // 4 Light output 1: headlights
#define LIGHT2 38                     // 5 Light output 2: headlights
#define LIGHT3 38                     // 18 Light output 3
#define LIGHT4 38                     // 19 Light output 4
#define BATTERYMONITOR 4              // 36 Analog input for battery voltage reading
#define INPUT1 1                      // 32 Input 1: sound trigger
#define INPUT2 2                      // 33 Input 2: sound trigger
#define INPUT3 3                      // 34 Input 3: station stop trigger
#define INPUT4 10                     // 35 Input 4: terminus stop trigger
#define NSLEEP 16                     // nSleep connected to EEP of DRV8833 module
#define FAULT  15                     // FAULT output connected to ULT of DRV8833 module
#define SD_MODE 41                    // SD/MODE pin of the MAX98357A Shutdown and Channel Select. Pull SD_MODE low to place the device in shutdown.

#define INPUTDEBOUNCE 250             // input software debounce delay
#define DRIVEMODE_DRIVING 0           // Shuttle mode: loco is driving, waiting for a station of terminus stop trigger
#define DRIVEMODE_STATIONBREAK 1      // Shuttle mode: station magnet detected, loco is slowing down to stop at a station
#define DRIVEMODE_STATIONSTOP 2       // Shuttle mode: loco is stopped at the station and counting down the wait time
#define DRIVEMODE_TERMINUSBREAK 3     // Shuttle mode: terminus magnet detected, loco is slowing down to stop at a terminus
#define DRIVEMODE_TERMINUSSTOP 4      // Shuttle mode: loco is stopped at the terminus and counting down the wait time

#define BATTARRSIZE 10                // Array size for averaging the battery reading
#define UDP_TIMEOUT 2000              // Stop the loco if UDP messages stop coming (2 sec)

String webStat = "";
String webMsg = "";

unsigned long lastMinute, uptime, lastSecond, sec, msgcount, lastDisplay, lastSpeed, lastInput1, lastInput2, lastInput3, lastInput4, lastSabertooth, lastUDP;
byte direction = 0;
byte speed = 0;
byte targetspeed = 0;
byte autospeed = 0;
byte drivemode = 0;
String configJSON;
int motorspeed, stationwait, blindtime, m1temp, m2temp;
bool lightState, light3State, light4State, input1State, input2State, shuttlemode, UDPActive;
float battery, m1current, m2current;
float battarr[BATTARRSIZE];
byte battarrcount = 0;
char startsound[6];
bool triggersound = false;
char packetBuffer[255]; //buffer to hold incoming packet

//auto led_breathe = JLed(jled::Esp32Hal(LIGHT1,2)).Off();
