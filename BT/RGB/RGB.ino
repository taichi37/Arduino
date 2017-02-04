#include <SoftwareSerial.h>
#include <Wire.h>
#define red 4
#define green 5
#define blue 6
SoftwareSerial BT( 3, 2 );
boolean stateRed = LOW;
boolean stateGreen = LOW;
boolean stateBlue = LOW;
char state[ 3 ] = { 10, 20, 30 };

void setup() {
  // put your setup code here, to run once:
  BT.begin( 9600 );
  pinMode( red, OUTPUT );
  pinMode( green, OUTPUT );
  pinMode( blue, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = BT.read();

  if( val == 49 )
  {
    if( stateRed == LOW )
      state[ 0 ] = 10;
    else
      state[ 0 ] = 11;

    if( stateGreen == LOW )
      state[ 1 ] = 20;
    else
      state[ 1 ] = 21;

    if( stateBlue == LOW )
      state[ 2 ] = 30;
    else
      state[ 2 ] = 31;

    BT.write( state );
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
