#define Light 8
#define oTime 800
#define sTime 300
#define offTime 300

void setup() {
  // put your setup code here, to run once:
  pinMode( Light, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i = 0 ; i < 3 ; i++ )
  {
    digitalWrite( Light, HIGH );
    delay( sTime );
    digitalWrite( Light, LOW );
    delay( offTime );
  }
  delay( 500 );
  
  for( int i = 0 ; i < 3 ; i++ )
  {
    digitalWrite( Light, HIGH );
    delay( oTime );
    digitalWrite( Light, LOW );
    delay( offTime );
  }
  delay( 500 );
  
  for( int i = 0 ; i < 3 ; i++ )
  {
    digitalWrite( Light, HIGH );
    delay( sTime );
    digitalWrite( Light, LOW );
    delay( offTime );
  }

  delay( 1000 );
}
