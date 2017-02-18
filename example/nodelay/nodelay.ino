#define ledPin 8
int ledState = LOW;            
long previousMillis = 0;       
long interval = 500;           
 
void setup()
{ 
    pinMode(ledPin, OUTPUT);      
}
 
void loop()
{
    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis > interval)
    {  
        previousMillis = currentMillis;   
    
        if (ledState == LOW)
        ledState = HIGH;
        else
        ledState = LOW;
    
        digitalWrite(ledPin, ledState);
    }
}



