#define SW 7
#define LED 8
byte Click = 0;
boolean b1, b2;
boolean lastStatus = LOW;
boolean ledStatus = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode( SW, INPUT );
  pinMode( LED, OUTPUT );
  digitalWrite( LED, ledStatus );
  lastStatus = digitalRead( SW );
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = digitalRead( SW );

  if( b1 != lastStatus )
  {
    delay( 20 );
    b2 = digitalRead( SW );
    if( b1 == b2 )
    {
      lastStatus = b1;
      Click ++;
    }
  }
  
  if( Click == 2 )
  {
    Click = 0;
    ledStatus = !ledStatus;
    digitalWrite( LED, ledStatus );  
  }
  
}

