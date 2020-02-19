// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>


#define BLYNK_PRINT Serial  // Set serial output for debug prints
//#define BLYNK_DEBUG       // Uncomment this to see detailed prints

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2fd02368df2749cbabafb6053834d03f";	//change the code between the "'s to your Blynk device code

//DHT Setup

#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT11		// DHT 11 

DHT dht(DHTPIN, DHTTYPE);


void setup()
{
  
    Blynk.begin(auth);
    delay (1000);
    dht.begin();
}




void loop()
{
    
    Blynk.run();
    
    	float h = dht.getHumidity();
    	float c = dht.getTempCelcius();
    	
    	// Check if any reads failed and exit early (to try again).
	if (isnan(h)  || isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}


Blynk.virtualWrite(V3, h);
Blynk.virtualWrite(V4, c);

    	
}
