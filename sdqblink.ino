// This one is the little blue LED on your board. On the Photon it is next to D7.
// Having declared these variables, let's move on to the setup function.
// The setup function is a standard part of any microcontroller program.
// It runs only once when the device boots up or is reset.


void setup() {
  // We are going to tell our device that D7 (which we named led) is going to be an output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)
  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.
  
  pinMode(led, OUTPUT);
  
}
// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.

void loop() {
  // To blink the LED, first we'll turn it on...
  digitalWrite(led, HIGH);

  // We'll leave it on for 1 second...
  delay(1000);
