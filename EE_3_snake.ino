#include <QueueArray.h>

namespace snakeBody{
  typedef struct{
    int x;
    int y;
  } body;
}

int myPins[16];
int myButtons[4];
int prevButtonState[4];
int buttonState = 0;
int i = 0;
int direction = 0;
unsigned long oldTime = 0;
const long interval = 1000;
QueueArray<int> body;

void setup(){
  for(i=0; i<16; i++){
    myPins[i] = i + 1;
    pinMode(myPins[i], OUTPUT);
  }
  for(i=0; i<4; i++){
    myButtons[i] = 16 + i + 1;
    pinMode(myButtons[i], INPUT);
    prevButtonState[i] = 0;
  }
  //  1
  // 2 3
  //  4
  // digitalWrite(snake, HIGH);
  // digitalWrite(apple, HIGH);
  Serial.begin(9600);
  Serial.println(" Hello World "); 
}

void loop(){
  unsigned long newTime = millis();
  if((newTime-oldTime)>=interval){
    newTime = oldTime;

    for(i=0; i<4; i++){
      buttonState = digitalRead(myButtons[i]);
      if(buttonState!=prevButtonState[i]){
        direction = i + 1;
      }
      prevButtonState[i] = buttonState;
    }

    if(direction==1){
      // move up
    }else if(direction==2){
      // move left
    }else if(direction==3){
      // move right
    }else if(direction==4){
      // move down
    }
  }

  // turns LED on
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  // turns LED off
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);


  // 8 x 8 LED matrix
  //
  //  0-7
  // 0
  // |
  // 7
  //
  // snake starts at (0,0)    digitalWrite(pin00, HIGH);
  // 
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
}
