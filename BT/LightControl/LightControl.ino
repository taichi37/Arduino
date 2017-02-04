#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT( 3, 2 );
const byte yellowSW = 12;
const byte yellowLED = 8;
boolean stateYellowSW;
boolean lastStateYellowSW = LOW;
boolean stateYellowLED = LOW;
long lastYellowTime = 0;
long delayTime = 20;

void setup() {
  BT.begin( 9600 );
  pinMode( yellowSW, INPUT );
  pinMode( yellowLED, OUTPUT );
  
}

void loop() {
  boolean yellow = digitalRead( yellowSW );
  int val = BT.read();
 
  if( val == 49 )
  {
    if( stateYellowLED == LOW )
      BT.write( 50 );
    else
      BT.write( 51 );  
  }


  if( val == 22 )
    stateYellowLED = !stateYellowLED;
 

  if( yellow != lastStateYellowSW )
    lastYellowTime = millis();

  if( ( millis() - lastYellowTime ) > delayTime )
  {
    if( yellow != stateYellowSW )
    {
      stateYellowSW = yellow;

      if( stateYellowSW == LOW )
        stateYellowLED = !stateYellowLED;
    }
  }

  digitalWrite( yellowLED, stateYellowLED );
  lastStateYellowSW = yellow;
}
