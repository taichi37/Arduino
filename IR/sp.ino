const byte IR = A0;
const byte Light = 7;
const byte Speaker = 8;
int val;
int Time = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode( Speaker, OUTPUT );
  pinMode( Light, OUTPUT );
  Serial.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead( IR );

  if( val > 600 )
  {
    digitalWrite( Light, HIGH );
    Time = 0;
  }
  else
  {
    if( Time > 10 )
    {
      digitalWrite( Light, LOW );
    }
    else
    {
      Serial.println( Time );
      Time += 1;
      delay( 1000 );
    }
    
  }
}
