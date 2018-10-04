#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6


// Exterieur = Jaune = Mass
Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800); //Test si NEO_RGB

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

uint16_t N;

// from Center
uint8_t rr, gg, bb;

uint16_t k, KK;

uint16_t pos, oldPos, diffPos;
String inputString = "";

uint8_t mode;

void setup() {

  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  N = strip.numPixels();

  k = 0;
  KK = 200;
  rr = random(255);
  bb = random(255);

  pos = 0;
  diffPos = 1;

  mode = 6;
  inputString.reserve(200);

  pinMode(PIN, OUTPUT);

  //digitalWrite(PIN, LOW);
}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  //LED_BUILTIN = led orange sur arduino
  
  inputString = "";

  while (Serial.available()) { // If data is available to read,
    char inChar = (char)Serial.read();
    
    if(inChar != '\n') {
      inputString += inChar;
      
    } else {

      clean();
 
      if(inputString.length() > 0) {
        byte tst = inputString.charAt(0);
        
        if( tst > 0 && tst < 17) {
          mode = (uint8_t)tst;
        }
    
      }
    }
  }
/*
 for(uint16_t i = 0; i<10; i++){
  strip.setPixelColor(i, strip.Color(100, 100, 100));
 }
 strip.show();
 delay(5);
*/

  switch (mode) {
    case 1: ambiance(); break;
    case 2: segment12on15();    break;
    case 3: strob();    break;
    case 4: vroum();    break;
    case 5: vroumContr();    break;
    case 6: vroumvroum(); break;
    case 13: dodgerBlue();  break;
    case 14: push14();  break;
    case 15: push15();  break;
    case 16: push16();  break;
    case 17: segment12on15();  break;
  }

}

// My behaviors
void clean() {
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}

void ambiance() {

  k++;

  if (k > KK) {
    rr = random(255);
    bb = random(255);
    k = 0;
  }

  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(0.7 * rr * (1 - cos(k * 2 * M_PI / KK)), 0.5 * bb * (1 - cos(k * 2 * M_PI / KK)), 0) );
  }

  strip.show();
  delay(5);

}


void vroum() {


  strip.setPixelColor((N + pos - 1) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos    ) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos + 1) % N, strip.Color(0, 0, 0));

  pos = (pos + diffPos);

  //  if(pos > N-3) {
  //    diffPos = -1;
  //  }

  if (pos > N)
    pos = pos - N;

  if (pos < 3)
    diffPos = 1;

  strip.setPixelColor((N + pos - 1) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos  ) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos + 1) % N, strip.Color(255, 0, 0));


  strip.show();
  delay(7);




  strip.setPixelColor(pos - 1, strip.Color(0, 0, 0));
  strip.setPixelColor(pos    , strip.Color(0, 0, 0));
  strip.setPixelColor(pos + 1, strip.Color(0, 0, 0));

  pos = pos + 3;

  if (pos > N)
    pos = pos - N;

  strip.setPixelColor(pos - 1, strip.Color(255, 0, 0));
  strip.setPixelColor(pos    , strip.Color(255, 0, 0));
  strip.setPixelColor(pos + 1, strip.Color(255, 0, 0));

  strip.show();

 // delay(1);
}



void vroumContr() {

  strip.setPixelColor((N + oldPos - 1) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + oldPos  ) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + oldPos + 1) % N, strip.Color(0, 0, 0));


  strip.setPixelColor((N + pos - 1) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos  ) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos + 1) % N, strip.Color(255, 0, 0));

  strip.show();
  delay(5);

}

void vroumvroum() {


  strip.setPixelColor((N + pos - 1) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos    ) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos + 1) % N, strip.Color(0, 0, 0));

  pos = (pos + diffPos);

  //  if(pos > N-3) {
  //    diffPos = -1;
  //  }

  if (pos > N)
    pos = pos - N;

  if (pos < 3)
    diffPos = 1;

  strip.setPixelColor((N + pos - 1) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos  ) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos + 1) % N, strip.Color(255, 0, 0));
  
  strip.setPixelColor((N + pos + 2) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos  + 3) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos + 4) % N, strip.Color(0, 0, 0));

  strip.setPixelColor((N + pos + 5) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos  + 6) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos + 7) % N, strip.Color(255, 0, 0));
  
  strip.setPixelColor((N + pos + 8) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos  + 9) % N, strip.Color(0, 0, 0));
  strip.setPixelColor((N + pos + 10) % N, strip.Color(0, 0, 0));

  strip.setPixelColor((N + pos + 11) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos  + 12) % N, strip.Color(255, 0, 0));
  strip.setPixelColor((N + pos + 13) % N, strip.Color(255, 0, 0));


  strip.show();
  delay(7);

}

void strobAlt() {

  for (uint16_t i = 0; i < N - 1; i++) {
    strip.setPixelColor(i % 2  , strip.Color(255, 255, 255));
    strip.setPixelColor(i % 2 + 1, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(50);


  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i % 2 + 1, strip.Color(255, 255, 255));
    strip.setPixelColor(i % 2  , strip.Color(0, 0, 0));
  }
  strip.show();
  delay(50);

}

void strob() {


  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(100, 100, 100));
  }
  strip.show();
  delay(20);


  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(80);

}



void strobSpread() {


  strip.setPixelColor(0, strip.Color(255, 255, 255));
  strip.setPixelColor(1, strip.Color(255, 255, 255));
  strip.setPixelColor(2, strip.Color(255, 255, 255));

  //  strip.setPixelColor(N/2 -1, strip.Color(255, 255, 255));
  //  strip.setPixelColor(N/2   , strip.Color(255, 255, 255));
  //  strip.setPixelColor(N/2 +1, strip.Color(255, 255, 255));

  strip.setPixelColor(N - 3, strip.Color(0, 0, 0));
  strip.setPixelColor(N - 2, strip.Color(0, 0, 0));
  strip.setPixelColor(N - 1, strip.Color(0, 0, 0));

  strip.show();
  delay(30);


  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.setPixelColor(1, strip.Color(0, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 0, 0));

  //  strip.setPixelColor(N/2 -1, strip.Color(0,0,0));
  //  strip.setPixelColor(N/2   , strip.Color(0,0,0));
  //  strip.setPixelColor(N/2 +1, strip.Color(0,0,0));

  strip.setPixelColor(N - 3, strip.Color(255, 255, 255));
  strip.setPixelColor(N - 2, strip.Color(255, 255, 255));
  strip.setPixelColor(N - 1, strip.Color(255, 255, 255));
  strip.show();
  delay(30);

}


void fromCenterSetup() {
  rr = random(255);
  gg = random(255);
  bb = random(255);

}

void fromCenter() {

  k++;

  if (k >= N / 2) {
    rr = random(255);
    gg = random(255);
    bb = random(255);
    k = 0;

    delay(1000);
  }

  for (uint16_t i = 0; i < k; i++) {
    strip.setPixelColor(N / 2 + i, strip.Color(rr, gg, bb));
    strip.setPixelColor(N / 2 - i, strip.Color(rr, gg, bb));
  }

  strip.show();
  delay(10);

}

// =======================================
// =======================================
// =======================================
// =======================================
// =======================================

void colorFill(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// all ribbon dodgerBlue
void dodgerBlue() {
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(30,144,255));
  }
  strip.show();
}

void push14() {
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(255,255,255));
  }
  strip.show();
}

void push15() {
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(255,100,0));
  }
  strip.show();
}

void push16() {
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(100,255,100));
  }
  strip.show();
}

void segment12on15(){
  for (uint16_t i = 0; i < N; i++) {
    strip.setPixelColor(i, strip.Color(100,255,100));
  }
  strip.show();
  }
