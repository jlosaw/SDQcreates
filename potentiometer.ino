// name the pins
#define POTPIN A0

// This routine runs only once upon reset
void setup()
{
  Serial.begin(9600);
}

// This routine loops forever
void loop()
{
 int analogValue = analogRead(POTPIN);       // read light sensor pin
 Serial.print("Analog Value: ");
 Serial.println(analogValue);

 delay(500);
}
