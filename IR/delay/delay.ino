#define IR A0
#define LED 8
#define delayTime 15
int val;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode( LED, OUTPUT );
  Serial.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead( IR );

  if( count > delayTime )
  {
    digitalWrite( LED, LOW );
    count = 0;
  }
  else if( val > 600 )
  {
    digitalWrite( LED, HIGH );
    count = 0;
  }
  else
  {
    count ++;
    delay( 1000 );
    Serial.println( count );
  }
}
