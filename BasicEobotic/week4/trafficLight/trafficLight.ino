#define redLed1 4
#define greenLed1 5
#define yellowLed1 12

#define redLed2 13
#define greenLed2 14
#define yellowLed2 15

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed1, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(yellowLed1, OUTPUT);

  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);
  pinMode(yellowLed2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  trafficLightStop(redLed2, yellowLed2, greenLed2);
  trafficLightGo(redLed1, yellowLed1, greenLed1);
  delay(5000);
  digitalWrite(redLed2, 0);
  trafficLightStop(redLed1, yellowLed1, greenLed1);
  trafficLightGo(redLed2, yellowLed2, greenLed2);
  delay(5000);
  digitalWrite(redLed1, 0);

}

void trafficLightGo(int redLed, int yellowLed, int greenLed) {
  digitalWrite(greenLed, 1);
  digitalWrite(yellowLed, 0);
  digitalWrite(redLed, 0);
}

void trafficLightStop(int redLed, int yellowLed, int greenLed){
  digitalWrite(greenLed, 0);
  digitalWrite(yellowLed, 1);
  delay(1000);
  digitalWrite(yellowLed, 0);
  digitalWrite(redLed, 1);
}