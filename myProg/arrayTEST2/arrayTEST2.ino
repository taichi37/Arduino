
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT( 3, 2 );
#define cds A5
#define LED 8
boolean stateLED = LOW;
long lastTime = 0;
long delayTime = 100;
byte Data[ 4 ] = { 0, 0, 0, 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  BT.begin( 9600 );
  pinMode( LED, OUTPUT );
  digitalWrite( LED, stateLED );
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead( cds );

  if( BT.available() )
  {
    int switchButton = BT.read();
    if( switchButton == 49 )
      stateLED = !stateLED;
  }

  if( stateLED == HIGH )
    Data[ 3 ] = 111;
  else
    Data[ 3 ] = 222;

  digitalWrite( LED, stateLED );
    
  if( millis() - lastTime > delayTime )
  {
    lastTime = millis();
    
    Serial.println( val );

    Data[ 0 ] = 'a';
    Data[ 1 ] = val / 256;
    Data[ 2 ] = val % 256;

    for( int j = 0 ; j < 4 ; j++ )
    {
      BT.write( Data[ j ] );
    }
  } 
}
