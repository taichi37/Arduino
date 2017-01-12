byte SW = 2;
byte Red = 12;
byte Click = 0;
boolean b1, b2;
boolean lastStatus = LOW;
boolean lightStatus = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode( SW, INPUT );
  pinMode( Red, OUTPUT );
  digitalWrite( Red, lightStatus );
  lastStatus = digitalRead( SW );
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = digitalRead( SW );


  if( Click == 2 )
  {
    Click = 0;
    lightStatus = !lightStatus;
    digitalWrite( Red, lightStatus );
  }
  else
  {
     
    while( b1 != lastStatus )
    {
      delay( 20 );
      lastStatus = b1;
      Click += 1;
    }
  }
}
