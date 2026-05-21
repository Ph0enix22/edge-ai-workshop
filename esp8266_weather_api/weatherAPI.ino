#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "YOUR_WIFI_NAME";   // change this
const char* password = "YOUR_WIFI_PASSWORD";  // change this

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, "http://wttr.in/Ballari?format=3");
    int code = http.GET();
    if (code > 0) {
      Serial.println(http.getString());
    }
    http.end();
  }
  delay(10000);
}
