// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>


// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN D2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("DHT11 test!");
	Particle.publish("state", "DHT11 test start");

	dht.begin();
	delay(2000);
}

void loop() {
// Wait a few seconds between measurements.
//	delay(2000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a 
// very slow sensor)
	float h = dht.getHumidity();
// Read temperature as Celsius
	float t = dht.getTempCelcius();
// Read temperature as Farenheit
	float f = dht.getTempFarenheit();
  
// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t) || isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

// Compute heat index
// Must send in temp in Fahrenheit!
	float hi = dht.getHeatIndex();
	float dp = dht.getDewPoint();
	float k = dht.getTempKelvin();

	Serial.print("Humid: "); 
	Serial.print(h);
	Serial.println("%");
	Serial.print("Temp: "); 
	Serial.print(t);
	Serial.println("*C ");
	Serial.print(f);
	Serial.println("*F ");
	Serial.print(k);
	Serial.println("*K");
	Serial.print("DewP: ");
	Serial.print(dp);
	Serial.println("*C");
	Serial.print("HeatI: ");
	Serial.print(hi);
	Serial.println("*C");
	Serial.println(Time.timeStr());

	//Publish the temp data to the console
Particle.publish("Temp C",String (t),60,PRIVATE);
Particle.publish("Humidity",String (h),60,PRIVATE);

	delay(3000);            //read sensor every XXXX milliseconds

}

