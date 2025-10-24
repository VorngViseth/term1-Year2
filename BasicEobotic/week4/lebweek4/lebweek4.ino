#define led1 10
#define led2 11
#define led3 12

#define button1  1
#define button2  2
#define button3  21


void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  

  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int input_on_pin2 = digitalRead(button2);
  int input_on_pin1 = digitalRead(button1);
  int input_on_pin21 = digitalRead(button3);

  while(input_on_pin2==0) {
    mode2();
    if(digitalRead(button1) == 0 || digitalRead(button3) ==0) {
      input_on_pin2=1;
    }
  }
  while(input_on_pin1==0) {
    mode1();
    if(digitalRead(button3)==0 || digitalRead(button2) ==0) {
      input_on_pin1=1;
    }
  }  
  while(input_on_pin21==0) {
    mode3();
    if(digitalRead(button1)==0 || digitalRead(button2) ==0) {
      input_on_pin21=1;
    }
  }

  close();
}

void mode1() {
  digitalWrite(led3 , 1);
  delay(200);
  digitalWrite(led2 , 1);
  delay(200);
  digitalWrite(led1 , 1);
  delay(200);

  digitalWrite(led3 , 0);
  delay(200);
  digitalWrite(led2 , 0);
  delay(200);
  digitalWrite(led1 , 0);
  delay(200);
}

void mode2() {
  digitalWrite(led1 ,1);
  delay(200);
  digitalWrite(led2 ,1);
  delay(200);
  digitalWrite(led3 ,1);
  delay(200);

  digitalWrite(led1 , 0);
  delay(200);
  digitalWrite(led2 , 0);
  delay(200);
  digitalWrite(led3 , 0);
  delay(200);
}

void mode3() {
  digitalWrite(led3 , 1);
  digitalWrite(led2 , 1);
  digitalWrite(led1 , 1);
  delay(200);

  digitalWrite(led3 , 0);
  digitalWrite(led2 , 0);
  digitalWrite(led1 , 0);
  delay(200);
}

void close() {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
