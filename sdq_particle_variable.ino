// -----------------------------------------
// Analog Value to Particle Variable
// -----------------------------------------
// In this example, we're going to register a Particle.variable() with the cloud so that we can read potentiometer.
// We'll also register a Particle.function so that we can turn the LED on and off remotely.

int pot = A0; // This is where your photoresistor is plugged in. The other side goes to the "power" pin (below).
int analogvalue; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the photoresistor.

void setup() {

    pinMode(pot,INPUT);  // Our photoresistor pin is input (reading the photoresistor)
    
    
    // We are going to declare a Particle.variable() here so that we can access the value of the photoresistor from the cloud.
    Particle.variable("analogvalue", &analogvalue, INT);
    // This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.
}


void loop() {

    // read the analog pin
    analogvalue = analogRead(pot);
    delay(100);

}
