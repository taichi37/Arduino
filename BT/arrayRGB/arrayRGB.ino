#include <SoftwareSerial.h>
#include <Wire.h>
#define red 4
#define green 5
#define blue 6
SoftwareSerial BT( 3, 2 );
boolean stateRed = LOW;
boolean stateGreen = LOW;
boolean stateBlue = LOW;

void setup() {
  // put your setup code here, to run once:
  BT.begin( 9600 );
  pinMode( red, OUTPUT );
  pinMode( green, OUTPUT );
  pinMode( blue, OUTPUT );
}

void loop() {
  byte Data[ 6 ];
  char val = BT.read();

  Data[ 0 ] = 'r';
  if( stateRed == LOW )
    Data[ 1 ] = 10;
  else
    Data[ 1 ] = 11;
    
  Data[ 2 ] = 'g';
  if( stateGreen == LOW )
    Data[ 3 ] = 20;
  else
    Data[ 3 ] = 21;
    
  Data[ 4 ] = 'b';
  if( stateBlue == LOW )
    Data[ 5 ] = 30;
  else
    Data[ 5 ] = 31;

  if( val == 49 )
  {
    for( int i = 0 ; i < 6 ; i++ )
      BT.write( Data[ i ] );

    val = 0;
  }
  
  if( val == 15 )
  {
    stateRed = ! stateRed;
  }
  else if( val == 25 )
  {
    stateGreen = !stateGreen;
  }
  else if( val == 35 )
  {
    stateBlue = !stateBlue;
  }

 
  digitalWrite( red, stateRed );
  digitalWrite( green, stateGreen );
  digitalWrite( blue, stateBlue );
       
}
