#define SW 7
#define LED 8

void setup() {
  // put your setup code here, to run once:
  pinMode( SW, INPUT );
  pinMode( LED, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean b1 = digitalRead( SW );
  
  if( b1 == 1 )
    digitalWrite( LED, HIGH );
  else
    digitalWrite( LED, LOW );
}
