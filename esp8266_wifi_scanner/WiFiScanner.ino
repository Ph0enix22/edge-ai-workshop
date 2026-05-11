#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Scanner ready...");
}

void loop() {
  int n = WiFi.scanNetworks();
  Serial.println("--- Networks Found ---");
  for (int i = 0; i < n; i++) {
    Serial.print(WiFi.SSID(i));
    Serial.print("   RSSI: ");
    Serial.println(WiFi.RSSI(i));
  }
  delay(5000);
}