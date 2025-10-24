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

  traffic(greenLed1, yellowLed1, redLed1, greenLed2, yellowLed2, redLed2);
  traffic(greenLed2, yellowLed2, redLed2, greenLed1, yellowLed1, redLed1);


}

void trafficGo(int greenLed, int yellowLed, int redLed){
  digitalWrite(greenLed, 1);
  digitalWrite(redLed, 0);
  digitalWrite(yellowLed, 0);
}

void trafficStop(int greenLed, int yellowLed, int redLed){
  digitalWrite(greenLed, 0);
  digitalWrite(redLed, 1);
  digitalWrite(yellowLed, 0);
}
void trafficYellow(int greenLed, int yellowLed, int redLed){
  digitalWrite(greenLed, 0);
  digitalWrite(redLed, 0);
  digitalWrite(yellowLed, 1);
}

void traffic(int green1, int yellow1, int red1, int green2, int yellow2, int red2) {
  trafficStop(green2, yellow2, red2);
  delay(500);
  trafficGo(green1, yellow1, red1);
  delay(5000);
  trafficYellow(green1, yellow1, red1);
  delay(1000);
}