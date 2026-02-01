// a: Blink the onboard LED and send status updates to the Serial Monitor
// p: GPIO 2 (Standard onboard LED for most ESP32 DevKits)

const int ledPin = 2;
void setup() {
  // Initialize serial communication at 115200 baud:
  Serial.begin(115200);
  // Set the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  Serial.println("ESP32 Booted. Starting blink cycle...");
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  Serial.println("Status: LED is ON");
  delay(1000); // Wait for 1 second
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  Serial.println("Status: LED is OFF");
  delay(1000); // Wait for 1 second
}
