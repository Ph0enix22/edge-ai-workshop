#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WIFI CONFIG
const char* ssid     = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";

ESP8266WebServer server(80);

void handleRoot() {
  int n = WiFi.scanNetworks();
  String html = "<html><body style='font-family:monospace;background:#0a0f1e;color:#fff;padding:20px'>";
  html += "<h2 style='color:#00d4ff'>ESP8266 Live Network Scan</h2><ul>";
  for (int i = 0; i < n; i++) {
    html += "<li>" + WiFi.SSID(i) + " &nbsp; <b>" + WiFi.RSSI(i) + " dBm</b></li>";
  }
  html += "</ul></body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nIP: " + WiFi.localIP().toString());
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}