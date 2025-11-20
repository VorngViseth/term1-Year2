#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "LittleFS.h"

// Motor driver pins
#define ATN1 25
#define ATN2 26
#define PWMA 33
#define STBY 4

WebServer server(80);
volatile int motorSpeed = 0;  // 0-255
bool forward = true;          // Motor direction

const char* SSID = "CADT-OFFICIALS";
const char* PASSWORD = "CADT@Ja&0z2kz$";

// Serve index.html
void handleRoot() {
  File fileHtml = LittleFS.open("/index.html", "r");
  if (!fileHtml) {
    server.send(404, "text/plain", "File not found");
    return;
  }
  server.streamFile(fileHtml, "text/html");
  fileHtml.close();
}

void handleScript() {
  File fileJs = LittleFS.open("/script.js", "r");
  server.streamFile(fileJs, "application/javascript");
  fileJs.close();
}

// Unified handler for both speed and direction
void handleMotorControl() {
  if (server.hasArg("plain")) {
    String body = server.arg("plain");
    
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, body);
    
    if (error) {
      server.send(400, "text/plain", "Invalid JSON");
      return;
    }
    
    // Handle speed if provided
    if (doc.containsKey("value")) {
      motorSpeed = doc["value"];
      Serial.printf("Speed updated to: %d\n", motorSpeed);
    }
    
    // Handle direction if provided
    if (doc.containsKey("dir")) {
      String dir = doc["dir"];
      if (dir == "forward") {
        forward = true;
        Serial.println("Direction: Forward");
      } else if (dir == "backward") {
        forward = false;
        Serial.println("Direction: Backward");
      }
    }
    
    server.send(200, "text/plain", "Motor control updated");
    
  } else {
    server.send(400, "text/plain", "No data received");
  }
}

void listLittleFS() {
  Serial.println("Files in LittleFS:");
  File root = LittleFS.open("/");
  File file = root.openNextFile();
  while(file) {
    Serial.println(file.name());
    file = root.openNextFile();
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

  // Mount LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("Failed to mount LittleFS");
    return;
  }

  listLittleFS();

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
  server.on("/script.js", handleScript);
  server.on("/setSpeedAndDirection", HTTP_POST, handleMotorControl);  // Single route for both

  server.enableCORS(true);
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