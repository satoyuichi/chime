#include <Wire.h>
#include "RTClib.h"

#define PLAY 6
#define STOP 2

RTC_DS1307 rtc;

void setup() {
  Serial.begin(57600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  // put your setup code here, to run once:
  pinMode(PLAY, OUTPUT);
  pinMode(STOP, OUTPUT);

  digitalWrite(STOP, HIGH);
  delay(100);  
  digitalWrite(STOP, LOW);
  digitalWrite(PLAY, LOW);

//  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  int m = now.minute();

//  if ((m % 5) == 0) {
//    chime ();
//  }
//  
  switch (now.hour()) {
  case 10:
  case 11:
  case 12:
    if ((m == 30) || (m == 40)) {
      chime ();
    }
    break;
  case 14:
  case 15:
    if ((m == 40) || (m == 50)) {
      chime ();
    }
    break;
  default:
    break;
  }

  delay(5000);  
}

void chime () {
  Serial.println("chime!!");
  
  digitalWrite(PLAY, HIGH);
  delay(10);  
  digitalWrite(PLAY, LOW);
  delay(10000);
  
  digitalWrite(STOP, HIGH);
  delay(10);  
  digitalWrite(STOP, LOW);
}

