  // 2-dimensional array of row pin numbers:
  const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
  };

  // 2-dimensional array of column pin numbers:
  const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
  };


// 2-dimensional array of pixels:
int pixels[8][8];

// cursor position:
int x = 5;
int y = 5;




int direction = 0;
unsigned long oldTime = 0;
const long interval = 500;
unsigned long newTime;
int count = 0;

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
    digitalWrite(row[thisPin], HIGH);
  }

  // initialize the pixel matrix:
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = HIGH;
    }
  }

}

void loop() {
  newTime = millis();
  if((newTime-oldTime)>=interval){
      oldTime = newTime;
      for(int i=0; i<8; i++){
        digitalWrite(col[i], LOW);
        digitalWrite(row[i], HIGH);
      }
      digitalWrite(col[4], HIGH);
      digitalWrite(row[4], LOW);
      digitalWrite(col[0], HIGH);
      digitalWrite(row[7], LOW);
    count = count + 1;
  }
}

//void readSensors() {
  /*// turn off the last position:
  pixels[x][y] = HIGH;
  // read the sensors for X and Y values:
  x = 7 - map(analogRead(A0), 0, 1023, 0, 7);
  y = map(analogRead(A1), 0, 1023, 0, 7);
  // set the new pixel position low so that the LED will turn on
  // in the next screen refresh:
  pixels[x][y] = LOW;*/
//}
