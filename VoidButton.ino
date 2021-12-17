#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#include <ESP8266WiFi.h>
#include <WiFiUDP.h>


const char* ssid = "Torquenet-2.0";
const char* password = "!WithThyMight!";
unsigned int port = 9324;
unsigned int buttonState;
WiFiUDP UDP;

void setup(void) {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000); 
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

void loop(void) {
  // Check if module is still connected to WiFi.
  if (WiFi.status() != WL_CONNECTED) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  } 

  if (digitalRead(2) == LOW) {
    UDP.beginPacket("192.168.1.201", port);
    UDP.write("YEAH", sizeof("YEAH"));
    UDP.endPacket();
  }
}
