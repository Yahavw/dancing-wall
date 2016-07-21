// The song is composed of identical parts. This method run 1 part with combications of colors - a,b,c
void bar1(uint8_t a, uint8_t b, uint8_t c) {
  // 3650 ms
  setColorForTime(letsStrip, dancingStrip.Color(a, b, c), 200); // lets
  setColorForTime(goStrip, dancingStrip.Color(c, a, b), 200); // go
  setColorForTime(dancingStrip, dancingStrip.Color(b, c, a), 500); // dancing
  delay(300);
  setColorForTime(strip, dancingStrip.Color(c, b, a), 200); // I
  setColorForTime(wannaStrip, dancingStrip.Color(b, a, c), 200); // wanna
  setColorForTime(goStrip, dancingStrip.Color(a, c, b), 300); //go
  setColorForTime(dancingStrip, dancingStrip.Color(a, b, c), 400); //dancing
  setColorForTime(withStrip, dancingStrip.Color(b, c, a), 300); // with
  setColorForTime(youStrip, dancingStrip.Color(c, a, b), 200); // you
  setColorForTime(allStrip, dancingStrip.Color(a, c, b), 250); // all
  setColorForTime(nightStrip, dancingStrip.Color(b, a, c), 200); // night
  setColorForTime(dancingStrip, dancingStrip.Color(c, b, a), 500); // dancing
}

void introLoop() {
  // 1200 ms
  setColorForTime(letsStrip, dancingStrip.Color(255, 127, 0), 200); // lets
  setColorForTime(goStrip, dancingStrip.Color(0, 255, 0), 200); // go
  setColorForTime(dancingStrip, dancingStrip.Color(127, 0, 255), 450); // dancing
  delay(300);

  // 2450 ms
  loopWords(130); 

  // 1650 ms
  loopWords(150); 

  loopWords(100); 

  loopWords(30); 
  loopWords(30); 

  // 1000
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(100);
  setAllStrips(dancingStrip.Color(0, 0, 255));
  delay(100);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(100);
  setAllStrips(dancingStrip.Color(0, 0, 255));
  delay(100);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(100);
  setAllStrips(dancingStrip.Color(0, 0, 255));
  delay(100);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(100);
  setAllStrips(dancingStrip.Color(0, 0, 255));
  delay(100);
  setAllStrips(dancingStrip.Color(0, 0, 0));
  //  delay(100);
}

// Set all strips with one color
void setAllStrips(uint32_t color)  {
  setColor(nightStrip, color); // all
  setColor(wannaStrip, color); // all
  setColor(dancingStrip, color); // all
  setColor(letsStrip, color); // all
  setColor(allStrip, color); // all
  setColor(withStrip, color); // all
  setColor(youStrip, color); // all
  setColor(goStrip, color); // all
  setColor(strip, color); // all
}

// set 
void setRow1(uint32_t color)  {
  setColor(withStrip, color); // all
  setColor(youStrip, color); // all
}

void setRow2(uint32_t color)  {
  setColor(allStrip, color); // all
  setColor(dancingStrip, color); // all
}

void setRow3(uint32_t color)  {
  setColor(strip, color); // all
  setColor(nightStrip, color); // all
  setColor(letsStrip, color); // all
}

void setRow4(uint32_t color)  {
  setColor(wannaStrip, color); // all
  setColor(goStrip, color); // all
}

// Roll over by rows. 
void rollRowUp(uint32_t color1, uint32_t color2, uint8_t wait) {
  setRow4(dancingStrip.Color(0, 0, 0));
  setRow1(color1);
  delay(wait);
  setRow2(color2);
  setRow1(dancingStrip.Color(0, 0, 0));
  delay(wait);
  setRow3(color1);
  setRow2(dancingStrip.Color(0, 0, 0));
  delay(wait);
  setRow4(color2);
  setRow3(dancingStrip.Color(0, 0, 0));
  delay(wait);
}

// Loop over the words
void loopWords(uint8_t wait) {
  setColor(dancingStrip, dancingStrip.Color(0, 0, 255)); // all
  setColorForTime(strip, dancingStrip.Color(204, 0, 204), wait); // lets
  setColorForTime(wannaStrip, dancingStrip.Color(0, 255, 0), wait); // go
  setColorForTime(goStrip, dancingStrip.Color(0, 128, 255), wait); // dancing
  setColorForTime(letsStrip, dancingStrip.Color(255, 175, 0), wait);
  setColorForTime(youStrip, dancingStrip.Color(0, 0, 255), wait); // I
  setColorForTime(withStrip, dancingStrip.Color(0, 255, 127), wait); // wanna
  setColorForTime(allStrip, dancingStrip.Color(0, 128, 255), wait); // you
  setColorForTime(nightStrip, dancingStrip.Color(127, 0, 255), wait); // all
  setColorForTime(letsStrip, dancingStrip.Color(255, 0, 255), wait); // lets
  setColorForTime(dancingStrip, dancingStrip.Color(255, 0, 0), wait); // all  
}


void fadeLeftToRight(uint8_t wait) {
    colorWipeByPart3Strips(allStrip, strip, withStrip, 3, dancingStrip.Color(10, 30, 100), wait);
    colorWipeByPart3Strips(wannaStrip, nightStrip, dancingStrip, 3, dancingStrip.Color(10, 30, 100), wait);
    colorWipeByPart3Strips(goStrip, letsStrip, youStrip, 3, dancingStrip.Color(10, 30, 100), wait);
  
    colorWipeByPart3Strips(allStrip, strip, withStrip, 3, dancingStrip.Color(204, 10, 204), wait);
    colorWipeByPart3Strips(wannaStrip, nightStrip, dancingStrip, 3, dancingStrip.Color(204, 10, 204), wait);
    colorWipeByPart3Strips(goStrip, letsStrip, youStrip, 3, dancingStrip.Color(204, 10, 204), wait);
}

// Light all words except of dancing --> 
void midLoop() {
  
  int a = (255) ;
  int b = (0 ) ;
  int c = (0 );
  setColorForTime(letsStrip, dancingStrip.Color(a, b, c), 200); // lets
  setColorForTime(goStrip, dancingStrip.Color(c, a, b), 200); // go
  setColorForTime(dancingStrip, dancingStrip.Color(b, c, a), 500); // dancing
  
  delay(300);

  // 2450
  setAllStrips(dancingStrip.Color(0,0,0));
  delay(150);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(150);
  setAllStrips(dancingStrip.Color(0,0,0));
  delay(150);
  setAllStrips(dancingStrip.Color(204, 0, 204));
 
  delay(150);
  setAllStrips(dancingStrip.Color(0,0,0));
  
  delay(150);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(150);
  setAllStrips(dancingStrip.Color(0,0,0));
  delay(150);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(150);
  setAllStrips(dancingStrip.Color(0,0,0));
  delay(150);
  setAllStrips(dancingStrip.Color(204, 0, 204));
  delay(150);
  setAllStrips(dancingStrip.Color(0,0,0));
  delay(150);
}

void afterMid() {
  bar1(0, 255, 255);

  setColorAndFadeOut(3, dancingStrip.Color(255, 0, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(0, 0, 255), 1);
  setColorAndFadeOut(3, dancingStrip.Color(255, 0, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(0, 0, 255), 1);
  setColorAndFadeOut(3, dancingStrip.Color(255, 0, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(0, 0, 255), 1);

  bar1(0, 127, 255);

  setColorAndFadeOut(3, dancingStrip.Color(127, 255, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(255, 0, 0), 1);
  setColorAndFadeOut(3, dancingStrip.Color(127, 255, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(255, 0, 0), 1);
  setColorAndFadeOut(3, dancingStrip.Color(127, 255, 0), dancingStrip.Color(0, 0, 0), dancingStrip.Color(255, 0, 0), 1);
 
  bar1(0, 0, 255);
  setColorAndFadeOut(3, dancingStrip.Color(127, 0, 255), dancingStrip.Color(0, 0, 0), dancingStrip.Color(128, 255, 0), 1);
  setColorAndFadeOut(3, dancingStrip.Color(127, 0, 255), dancingStrip.Color(0, 0, 0), dancingStrip.Color(128, 255, 0), 1);
  setColorAndFadeOut(3, dancingStrip.Color(127, 0, 255), dancingStrip.Color(0, 0, 0), dancingStrip.Color(128, 255, 0), 1);
}

