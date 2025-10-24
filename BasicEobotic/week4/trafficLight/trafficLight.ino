#define redLed1 4
#define greenLed1 5
#define yellowLed1 12

#define redLed2 13
#define greenLed2 14
#define yellowLed2 15

#define redLed3 42
#define greenLed3 41
#define yellowLed3 40

#define redLed4 37
#define greenLed4 39
#define yellowLed4 38

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed1, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(yellowLed1, OUTPUT);

  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);
  pinMode(yellowLed2, OUTPUT);

  pinMode(redLed3, OUTPUT);
  pinMode(greenLed3, OUTPUT);
  pinMode(yellowLed3, OUTPUT);  

  pinMode(redLed4, OUTPUT);
  pinMode(greenLed4, OUTPUT);
  pinMode(yellowLed4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  trafficStop(greenLed3, yellowLed3, redLed3);
  trafficStop(greenLed4, yellowLed4, redLed4);
  traffic(greenLed1, yellowLed1, redLed1, greenLed2, yellowLed2, redLed2);
  traffic(greenLed2, yellowLed2, redLed2, greenLed1, yellowLed1, redLed1);

  trafficStop(greenLed1, yellowLed1, redLed1);
  trafficStop(greenLed2, yellowLed2, redLed2);
  traffic(greenLed3, yellowLed3, redLed3, greenLed4, yellowLed4, redLed4);
  traffic(greenLed4, yellowLed4, redLed4, greenLed3, yellowLed3, redLed3);


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