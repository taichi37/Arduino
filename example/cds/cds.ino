#include <SoftwareSerial.h>
#include <Wire.h>
#define cds A5
#define LED 8

SoftwareSerial BT( 3, 2 );
boolean stateLED = LOW;
long lastTime = 0;
long delayTime = 200;
int controlState = 100;
byte Data[ 4 ] = { 0, 0, 0, 0 };

void setup() {
  // put your setup code here, to run once:
  BT.begin( 9600 );
  Serial.begin( 9600 );
  pinMode( LED, OUTPUT );
}

void loop() {
  int val = analogRead( cds );

   

    if( stateLED == LOW )
      Data[ 3 ] = 77;
    else
      Data[ 3 ] = 88;

    if( millis() - lastTime > delayTime )
    {
       lastTime = millis();
       Serial.println( val );

       BT.write( val / 4 );
       Data[ 0 ] = 'a';
       Data[ 1 ] = val / 256;
       Data[ 2 ] = val % 256;
       
      // for( int j = 0 ; j < 4 ; j++ )
      // {
         // BT.write( Data[ j ] );
      // }
    }

    if( BT.available() )
      controlState = BT.read();

    switch( controlState )
    {
        case 100 :
        //if( controlState == 100 )
        //{
          if( val > 500 )
            stateLED = HIGH;
          else if( val < 400 )
            stateLED = LOW; 
        //}
        break;
        case 111 :
        //if( controlState == 222 )
        //{
            stateLED = !stateLED;
        //}
        break;
    }
  digitalWrite( LED, stateLED ); 

  

  
}
