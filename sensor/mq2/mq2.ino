#define sr A0
#define r 5
#define g 6
#define b 7
unsigned long interval = 999;
unsigned long previousTime = 0;
int def, val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  pinMode( r, OUTPUT );
  pinMode( g, OUTPUT );
  pinMode( b, OUTPUT );
  def = analogRead( sr );
  val = analogRead( sr );
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  unsigned long sTime = currentTime - previousTime;
     
  if( sTime > interval )
  {
    val = analogRead( sr );
    Serial.println( val );
    //Serial.println( sTime );
    previousTime = millis();
  }

  if( val > 200 )
  {
    digitalWrite( r, HIGH );
    digitalWrite( g, LOW );
    digitalWrite( b, LOW );
  }
  else if( val > def * 1.2 )
  {
    digitalWrite( r, LOW );
    digitalWrite( g, LOW );  
    digitalWrite( b, HIGH ); 
  }
  else
  {
    digitalWrite( r, LOW );
    digitalWrite( g, HIGH );
    digitalWrite( b, LOW );
  }
}
