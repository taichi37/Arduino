#include <SoftwareSerial.h>
#include <Wire.h>
#define cds A5

SoftwareSerial BT( 3, 2 );
const byte yellowLED = 8;
long lastTime = 0;
long delayTime = 200;
int controlState = 100;

void setup() {
  // put your setup code here, to run once:
  BT.begin( 9600 );
  Serial.begin( 9600 );
  pinMode( yellowLED, OUTPUT );
}

void loop() {
  int val = analogRead( cds );

  if( millis() - lastTime > delayTime )
    {
      lastTime = millis();
      Serial.println( val );
      BT.write( (val / 4) );
    }

    if( BT.available() )
      controlState = BT.read();
    
    if( controlState == 100 )
    {
      if( val > 500 )
        digitalWrite( yellowLED, HIGH );
      else
        digitalWrite( yellowLED, LOW ); 
    }
    else
    {
      if( controlState == 111 )
        digitalWrite( yellowLED, HIGH );
      else if( controlState == 222 )  
        digitalWrite( yellowLED, LOW );
    }
        
  

  

  
}
