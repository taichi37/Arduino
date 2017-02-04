#include <SoftwareSerial.h>
#include <Wire.h>
#define red 4
#define green 5
#define blue 6
byte count = 0;
byte count2 = 0;
byte count3 = 0;
SoftwareSerial BT( 3, 2 );

void setup() {
  // put your setup code here, to run once:
  BT.begin( 9600 );
  pinMode( red, OUTPUT );
  pinMode( green, OUTPUT );
  pinMode( blue, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = BT.read();

  if( val == 11 )
  {
    count ++;
    
    if( count == 2 )
    {
      count = 0;
      digitalWrite( green, LOW );
    }
    else
    {
      if( count == 1 )
      {
        digitalWrite( green, HIGH );
      }
    }
  }

  
  if( val == 22 )
  {
    count2 ++;
    
    if( count2 == 2 )
    {
      count2 = 0;
      digitalWrite( red, LOW );
    }
    else
    {
      if( count2 == 1 )
      {
        digitalWrite( red, HIGH );
      }
    }
  }


  if( val == 33 )
  {
    count3 ++;
    
    if( count3 == 2 )
    {
      count3 = 0;
      digitalWrite( blue, LOW );
    }
    else
    {
      if( count3 == 1 )
      {
        digitalWrite( blue, HIGH );
      }
    }
  }
  
}
