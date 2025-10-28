#include "WiFi.h" 

#define redLed 4
#define yellowLed 5
#define greenLed 13
  
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  WiFi.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scanning available networks..");
  digitalWrite(redLed, 0);
  digitalWrite(greenLed, 0);
  digitalWrite(yellowLed, 1);
  
  int wifi = WiFi.scanNetworks();
  if(wifi != 0) {
    Serial.print(wifi);
    Serial.println(" network(s) found : ")
    for(int i = 0; i < wifi; i++) {
      Serial.print("network "); Serial.print(i+1); Serial.print(" : ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" ("); Serial.print(WiFi.RSSI(i)); Serial.print(" dbm"); Serial.print(")"); 
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " open " : " *** ");
      delay(50);
    }
  }
  else {
    Serial.println("No available networks");
    digitalWrite(redLed, 1);
    digitalWrite(greenLed, 0);
    digitalWrite(yellowLed, 0);
  }

  delay(5000);

}
