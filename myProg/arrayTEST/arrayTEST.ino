#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT( 3, 2 );
#define cds A5
#define relay 10
long lastTime = 0;
long delayTime = 200;
byte Data[ 3 ] = { 0, 0, 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  BT.begin( 9600 );
  pinMode( relay, OUTPUT );
  digitalWrite( relay, HIGH );
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead( cds );

  if( val > 500 )
    digitalWrite( relay, LOW );
  else
    digitalWrite( relay, HIGH );
    
  if( millis() - lastTime > delayTime )
  {
    lastTime = millis();
    
    Serial.println( val );

    Data[ 0 ] = 'a';
    Data[ 1 ] = val / 256;
    Data[ 2 ] = val % 256;

    for( int j = 0 ; j < 3 ; j++ )
    {
      BT.write( Data[ j ] );
    }
  } 
}
