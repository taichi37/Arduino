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
  // put your main code here, to run repeatedly:
  char val = BT.read();

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
