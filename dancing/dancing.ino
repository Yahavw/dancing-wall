#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

//#define FAST 50
//#define MEDIUM 150
//#define SLOW 500
#define STRIP5M 150


#define DANCING 3
#define I       4
#define WANNA   5
#define WITH    6
#define YOU     7
#define ALL     8
#define NIGHT   9
#define LETS    11
#define GO      12

// Input pins
int pirPin = 18;
int buttonPin = 19;

int ledPin = 13;                // choose the pin for the LED

volatile int state = LOW;
volatile int pirInterrupt = LOW;
volatile int buttonInterrupt = LOW;

boolean running = false;


//############################ Strips Configuration ############################
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel letsStrip = Adafruit_NeoPixel(STRIP5M, LETS, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel goStrip = Adafruit_NeoPixel(STRIP5M, GO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dancingStrip = Adafruit_NeoPixel(STRIP5M, DANCING, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, I, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel wannaStrip = Adafruit_NeoPixel(STRIP5M, WANNA, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel withStrip = Adafruit_NeoPixel(STRIP5M, WITH, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel youStrip = Adafruit_NeoPixel(STRIP5M, YOU, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel allStrip = Adafruit_NeoPixel(STRIP5M, ALL, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel nightStrip = Adafruit_NeoPixel(STRIP5M, NIGHT, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin (9600);

  // Define I/O
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  pinMode(buttonPin, INPUT);     // declare sensor as input


  // Initialize all strips
  letsStrip.begin();
  goStrip.begin();
  dancingStrip.begin();
  strip.begin();
  wannaStrip.begin();
  withStrip.begin();
  youStrip.begin();
  allStrip.begin();
  nightStrip.begin();

  letsStrip.show();
  goStrip.show();
  dancingStrip.show();
  strip.show();
  wannaStrip.show();
  withStrip.show();
  youStrip.show();
  allStrip.show();
  nightStrip.show();

  // Attach an interrupt to the ISR vector
  attachInterrupt(4, pin_ISR, RISING);
  attachInterrupt(5, pin_ISR, RISING);

}

void pin_ISR() {
 // *The  running loop can be located here. the problem is that it is too long to be in interrupt session.
    if (state == LOW && !running) {
      digitalWrite(ledPin, HIGH);
      state = HIGH;
    }
}

void loop() {
  if (state == HIGH) {
    running = true;
    char ard_sends = '1';
    Serial.print(ard_sends);

    // Wait for audio player(pc) to be ready
    while (Serial.read() != '0') {}
    
    Serial.flush();
    // Maybe some delay should be added here
    runAll();
    finish();

  } else {
    // Standby program
    colorWipeByPart(dancingStrip, 3, dancingStrip.Color(0, 255, 0), 50);
    colorWipeByPart(dancingStrip, 3, dancingStrip.Color(0, 0, 255), 50);
  }
}

void runAll() {
  introLoop();
  bar1(255, 0, 0);
  bar1(255, 127, 0);
  bar1(255, 255, 0);
  bar1(127, 255, 0);
  bar1(0, 255, 0);
  
  fadeLeftToRight(10);
  fadeLeftToRight(10);
  fadeLeftToRight(10);
    
  bar1(0, 255, 127);
  
  midLoop();

  afterMid();
  
  // #################
  
  introLoop();
  
  delay(250);
  setColor(letsStrip, dancingStrip.Color(0, 127, 255)); // lets
  delay(200);
  setColor(goStrip, dancingStrip.Color(255, 255, 0)); // go
  delay(200);
  setColor(dancingStrip, dancingStrip.Color(204, 0, 204)); // dancing
  delay(800);
  
  char ard_sends = '0';
  Serial.print(ard_sends);
  Serial.flush();

  colorWipeByPart(dancingStrip, 3, dancingStrip.Color(0, 0, 0), 25);
  colorWipeByPart(letsStrip, 3, dancingStrip.Color(0, 0, 0), 25);
  colorWipeByPart(goStrip, 3, dancingStrip.Color(0, 0, 0), 25);
  
  
  setAllStrips(dancingStrip.Color(0, 0, 0));
}

void finish() {
    char ard_sends = '0';
  Serial.print(ard_sends);
  Serial.flush();
  
  state = LOW;
  digitalWrite(ledPin, LOW);
  running = false;
}




