/*
 * 開關彈跳 - 軟體
 * 此程式配合下拉電阻(10k)的電路
 */
#define Button  12
#define LED 8
boolean stateButton;
boolean lastStateButton = LOW;
boolean stateLED = LOW;
long lastDebounceTime = 0;
long debounceTime = 20;

void setup()
{
  pinMode( Button, INPUT );
  pinMode( LED, OUTPUT );
}


void loop()
{
	boolean readSW = digitalRead( Button );

	if( readSW != lastStateButton )
		lastDebounceTime = millis();

	if( ( millis() - lastDebounceTime ) > debounceTime )
	{
		if( readSW != stateButton )
		{
			stateButton = readSW;

			if( stateButton	== LOW )
				stateLED = !stateLED;
		}
	}

	digitalWrite( LED, stateLED );
	lastStateButton = readSW;
}






