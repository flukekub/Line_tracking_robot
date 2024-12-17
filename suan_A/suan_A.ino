#include <Servo.h>
int value = 0;  // set values you need to zero

Servo firstESC, secondESC;
#include <EEPROM.h>
#define smid 800


#define ADDkp 12
#define ADDki 18
#define ADDkd 24
#define ADDAlpha 30
#define buzzer 12

double kp = 1;
double ki = 3000.00;
double kd = 8;  //7,5
double Alpha = 0.00;

int kps = 0;
int kis = 0;
int kds = 0;
int Alphas = 0;

byte Readbyte = 0;
int Data, Status;
int PV, Setpoint = 0;

float motorspeed;
int serror[10] = { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 };
int smin[10] = { 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023 };
int smax[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
float sensor[10];
float ssum;
float error;
int last_error = 0;

int integrel;
int diff = 0;
void setup() {
  Serial3.begin(9600);
  /* 
  kps = EEPROMreadInt(ADDkp);
  kis = EEPROMreadInt(ADDki);
  kds = EEPROMreadInt(ADDkd);
  Alphas = EEPROMreadInt(ADDAlpha);
  kp = EEPROMreadInt(ADDkp) / 1000.0;
  ki = EEPROMreadInt(ADDki) / 1000.0;
  kd = EEPROMreadInt(ADDkd) / 1000.0;
  Alpha = EEPROMreadInt(ADDAlpha)/1000;
  */
  set_module();
}

void loop() {
  // Serial.println(sensor_read(14));
  //while(1){sensor_test();}
  value = 1400;

  for (int i = 1000; i < 1500; i++) {
    firstESC.writeMicroseconds(i);
    delay(10);
  }
  digitalWrite(13, LOW);

  beep();
  while (1) {
    track();
  }

  /*track_h();
   black();
   motor(0,0);
   motor(-100,90);
   while(sensor_read(3)<10);
   motor(0,0);
  track_hr();*/
}
