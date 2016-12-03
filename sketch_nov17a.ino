#include <snakey8.h>
#include <QueueArray.h>

  // 2-dimensional array of row pin numbers:
  const int row[8] = {
  // 2, 7, 19, 5, 13, 18, 12, 16
  16, 12, 18, 13, 5, 19, 7, 2
  };

  // 2-dimensional array of column pin numbers:
  const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
  };

unsigned long oldTime = 0;
const long interval = 1200;
unsigned long newTime;
Map* m;
int leftButton = HIGH;
int rightButton = HIGH;
int left = 0;
int right = 0;

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(col[thisPin], LOW);
    //digitalWrite(row[thisPin], HIGH);
    digitalWrite(row[thisPin], LOW);
  }
  m = new Map();
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  m->printMap();
  newTime = millis();
  if((newTime-oldTime)>=interval){
    oldTime = newTime;
    if(left==1){
      m->getSnake()->changeDir(-1);
      left = 0;
    }
    if(right==1){
      m->getSnake()->changeDir(1);
      right = 0;
    }
    if(m->move()==1){
      pS(1);
    }
  }
  if(left==0){
    leftButton = digitalRead(A0);
    if(leftButton==LOW){
      left = 1;
    }
  }
  if(right==0){
    rightButton = digitalRead(A1);
    if(rightButton==LOW){
      right = 1;
    }
  }
  if(leftButton==LOW || rightButton==LOW){
    Serial.println(0);
  }else{
    Serial.println(1);
  }
}

void pS(int state){
  if(state==1){
    for(int i=0; i<8; i++){
      digitalWrite(col[i], LOW);
      digitalWrite(row[i], HIGH);
    }
  }else{
    for(int i=0; i<8; i++){
      digitalWrite(col[i], HIGH);
      digitalWrite(row[i], LOW);
    }
  }
  delay(500);
}

