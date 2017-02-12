#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT( 3, 2 );
#define cds A5
long lastTime = 0;
long delayTime = 200;
byte num1, num2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  BT.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead( cds );
    
  if( millis() - lastTime > delayTime )
  {
    lastTime = millis();
    
    Serial.println( val );

    num1 = val / 256;
    num2 = val % 256;

    BT.print( "begin" );
    BT.print( "|" );
    BT.print( num1 );
    BT.print( "|" );
    BT.println( num2 );
    
  } 
}
