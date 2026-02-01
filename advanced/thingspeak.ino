// a: Read DHT11 Temp/Humidity and upload to ThingSpeak
// p: GPIO 4 (Data Pin)

#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// --- Configuration ---
const char* ssid = "XXXXXXXXX"; // Your WiFi SSID
const char* password = "XXXXXXXX"; // Your WiFi Password
unsigned long myChannelNumber = XXXXXXXXX; // Your Channel ID
const char* myWriteAPIKey = "XXXXXXXXXXX"; // Your Write API Key
                                           //
#define DHTPIN 4 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // Specifying the sensor type
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

  ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print to Serial Monitor
  Serial.print("Temp: "); Serial.print(t);
  Serial.print("°C | Humidity: "); Serial.print(h); Serial.println("%");

  // Write to ThingSpeak Fields
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if(x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  // ThingSpeak free version limits updates to once every 15 seconds
  delay(20000);
}
