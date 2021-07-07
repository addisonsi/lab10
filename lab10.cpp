/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/addisonsimon/lab10/src/lab10.ino"
#include <Wire.h>
void setup();
void loop();
#line 2 "/Users/addisonsimon/lab10/src/lab10.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);
char ch;
// setup() runs once, when the device is first turned on.
void setup()
{
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  while (!Serial.isConnected());
  
  Wire.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  Serial.println("Test");
  if(Serial.available()){
    ch = Serial.read();
    if(ch != '?'){                                  
      Wire.beginTransmission(0x2A);
      Wire.write(ch);
      Wire.endTransmission();
    }
    else{
      Wire.requestFrom(0x2A, 1);
      while (Wire.available() == 0);
      bool value = Wire.read();
      if(value)
        Serial.println("HIGH");
      else
        Serial.println("LOW");
    }
  }
}