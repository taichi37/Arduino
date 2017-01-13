#define red 9
#define green 10
#define yellow 11

void setup() {
  // put your setup code here, to run once:
  pinMode( red, OUTPUT );
  pinMode( green, OUTPUT );
  pinMode( yellow, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( green, HIGH );
  delay( 10000 );
  digitalWrite( green, LOW );
  delay( 100 );

  for( int i = 0 ; i < 3 ; i++ )
  {
    digitalWrite( yellow, HIGH );
    delay( 500 );
    digitalWrite( yellow, LOW );
    delay( 500 );
  }

  digitalWrite( red, HIGH );
  delay( 10000 );
  digitalWrite( red, LOW );
  delay( 100 );
}
