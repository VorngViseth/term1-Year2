#include <WiFi.h>
#include <WebServer.h>
#include "SPIFFS.h"

// Motor driver pins
#define ATN1 25
#define ATN2 26
#define PWMA 33
#define STBY 4

WebServer server(80);
volatile int motorSpeed = 128;  // 0-255
bool forward = true;            // Motor direction

const char* SSID = "Seth At Home";
const char* PASSWORD = "Seth098573231";

// Serve index.html
void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    server.send(404, "text/plain", "File not found");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}

// Set motor speed
void handleSetSpeed() {
  if (server.hasArg("value")) {
    motorSpeed = server.arg("value").toInt();
    Serial.printf("Speed updated to: %d\n", motorSpeed);
    server.send(200, "text/plain", "Speed changed");
  } else {
    server.send(400, "text/plain", "Missing value");
  }
}

void setup() {
  Serial.begin(9600);

  // Motor pins
  pinMode(ATN1, OUTPUT);
  pinMode(ATN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  // Mount SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }

  // Connect WiFi
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.println(WiFi.localIP());

  // Routes
  server.on("/", handleRoot);
  server.on("/setSpeed", handleSetSpeed);

  // Set motor direction
  server.on("/setDirection", HTTP_GET, []() {
    if (server.hasArg("dir")) {
      String dir = server.arg("dir");
      if (dir == "forward") forward = true;
      else if (dir == "backward") forward = false;
      server.send(200, "text/plain", "Direction set");
    } else {
      server.send(400, "text/plain", "Missing dir");
    }
  });

  // Optional: get current speed
  server.on("/getSpeed", HTTP_GET, []() {
    server.send(200, "text/plain", String(motorSpeed));
  });

  server.begin();
}

void loop() {
  server.handleClient();

  // Set motor direction
  if (forward) {
    digitalWrite(ATN1, HIGH);
    digitalWrite(ATN2, LOW);
  } else {
    digitalWrite(ATN1, LOW);
    digitalWrite(ATN2, HIGH);
  }

  // Software PWM
  for (int i = 0; i < 255; i++) {
    digitalWrite(PWMA, HIGH);
    delayMicroseconds(motorSpeed);
    digitalWrite(PWMA, LOW);
    delayMicroseconds(255 - motorSpeed);
  }
}
