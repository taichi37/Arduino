#define SW 7
#define LED 8
boolean lastStatus = LOW;
int Click = 0;
int switchStatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode( SW, INPUT );
  pinMode( LED, OUTPUT );
}

void count()
{
  boolean b1 = digitalRead( SW );

  if( Click == 2 )
  {
    Click = 0;
    //ledStatus = !ledStatus;
    //digitalWrite( LED, ledStatus );
    switchStatus ++;
  }
  else
  {
    if( b1 != lastStatus )
    {
      delay( 20 );
      boolean b2 = digitalRead( SW );
      if( b1 == b2 )
      {
        Click ++;
        lastStatus = b1;
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  count();
  
  if( switchStatus > 2 )
    switchStatus = 0;

  if( switchStatus == 1 )
  {
    digitalWrite( LED, HIGH );
  }
  else if( switchStatus == 2 )
  {
    digitalWrite( LED, LOW );
    while( switchStatus == 2 )
    {
      count();
      digitalWrite( LED, HIGH );
      delay( 100 );
      count();
      digitalWrite( LED, LOW );
      delay( 100 );
    }
  }
  else
  {
    digitalWrite( LED, LOW );
  }

}
