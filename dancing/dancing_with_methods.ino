

void setColor(Adafruit_NeoPixel &strip, uint32_t color) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void setColorOnlyEven(Adafruit_NeoPixel &strip, uint32_t color) {
  for (uint16_t i = 0; i < strip.numPixels(); i = i + 2) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void setColorForTime(Adafruit_NeoPixel &strip, uint32_t color, uint16_t timeToShow) {
  setColor(strip, color);
  delay(timeToShow);
  resetStrip(strip);
}

void resetStrip(Adafruit_NeoPixel &strip) {
  setColor(strip, strip.Color(0, 0, 0 ));
}
//############################ Set by Parts Methods ############################

void setPart(Adafruit_NeoPixel &strip, uint8_t thisPartNumber, uint8_t totalParts, uint32_t color, uint16_t timeToShow) {
  int startLed = (strip.numPixels() / totalParts) * thisPartNumber;
  int endLed = (strip.numPixels() / totalParts) * (thisPartNumber + 1) ;
  for (uint16_t i = startLed; i < endLed ; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  delay(timeToShow);
  resetStrip(strip);
}

void curtainByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint32_t color, uint8_t wait, uint32_t timeToPlay) {
  int ledsInPart = (strip.numPixels() / totalParts);
  for (uint16_t j =  0; j < totalParts; j++) {
    for (uint16_t i = 0; i < ledsInPart; i++) {
      strip.setPixelColor(i + (j * ledsInPart), color);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}

//############################ flickering Methods ############################

void flickering(Adafruit_NeoPixel &strip, uint32_t color, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}


void flickering2Colors(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum ; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, firstColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, secondColor);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}

void flickering2ColorsNoReset(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum ; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, firstColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, secondColor);
    }
    strip.show();
    delay(wait);
  }

}

void flickering3Colors(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, firstColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, secondColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, thirdColor);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}

//############################ Even/Odd Methods ############################
void flickeringOddEven(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i += 2) {
      strip.setPixelColor(i, firstColor);
      strip.setPixelColor(i + 1, secondColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i += 2) {
      strip.setPixelColor(i, secondColor);
      strip.setPixelColor(i + 1, firstColor);
    }
    strip.show();
    delay(wait);
  }
}

void flickeringOddEvenForTime(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i += 2) {
      strip.setPixelColor(i, firstColor);
      strip.setPixelColor(i + 1, secondColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i += 2) {
      strip.setPixelColor(i, secondColor);
      strip.setPixelColor(i + 1, firstColor);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}

void flickeringModulo3(Adafruit_NeoPixel &strip, uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, uint8_t wait, uint32_t timeToPlay) {
  int externalLoopsNum = (timeToPlay / (2 * wait));
  for (uint16_t j = 0; j < externalLoopsNum; j++) {
    for (uint16_t i = 0; i < strip.numPixels(); i += 3) {
      strip.setPixelColor(i, firstColor);
      strip.setPixelColor(i + 1, secondColor);
      strip.setPixelColor(i + 2, thirdColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i += 3) {
      strip.setPixelColor(i, thirdColor);
      strip.setPixelColor(i + 1, firstColor);
      strip.setPixelColor(i + 2, secondColor);
    }
    strip.show();
    delay(wait);
    for (uint16_t i = 0; i < strip.numPixels(); i += 3) {
      strip.setPixelColor(i, secondColor);
      strip.setPixelColor(i + 1, thirdColor);
      strip.setPixelColor(i + 2, firstColor);
    }
    strip.show();
    delay(wait);
  }
  resetStrip(strip);
}

//############################ Other Methods ############################


// Fill the dots one after the other with a color
void colorWipeByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint32_t color, uint8_t wait) {
  int led = strip.numPixels() / totalParts;
  for (uint16_t i = 0; i < led; i++) {
    for (uint16_t j =  0; j < totalParts; j++) {
      strip.setPixelColor(i + (j * led), color);
    }
    strip.show();
    delay(wait);
  }
}

void rainbowByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint8_t wait) {
  uint16_t i, j, q;
  int led = strip.numPixels() / totalParts;
  for (uint16_t j = 0; j < 256; j++) {
    for (uint16_t i = 0; i < led ; i++ ) {
      for (uint16_t q =  0; q < totalParts; q++) {
        strip.setPixelColor(i + (q * led), Wheel((i + j) & 255));
      }

    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycleByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint8_t wait) {
  uint16_t i, j, q;
  int led = strip.numPixels() / totalParts;
  for (j = 0; j < 256; j++) {
    for (uint16_t i = 0; i < led ; i++ ) {
      for ( q =  0; q < totalParts; q++) {
        strip.setPixelColor(i + (j * led), Wheel(((i * 256 / (strip.numPixels() / totalParts)) + j) & 255));
      }

    }
    strip.show();
    delay(wait);
  }
}

void theaterChaseByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint32_t color, uint8_t wait) {
  int led = strip.numPixels() / totalParts;
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < led ; i = i + 3 ) {
        for ( int k =  0; k < totalParts; k++) {
          strip.setPixelColor(i + q + (k * led), color);  //turn every third pixel on
        }

      }
      strip.show();
      delay(wait);
      for (uint16_t i = 0 ; i < led ; i = i + 3 ) {
        for ( int k =  0; k < totalParts; k++) {
          strip.setPixelColor(i + q + (k * led), 0);  //turn every third pixel on
        }
      }
    }
  }
}

void theaterChaseRainbowCycleByPart(Adafruit_NeoPixel &strip, uint8_t totalParts, uint8_t wait) {
  int led = strip.numPixels() / totalParts;
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < led ; i = i + 3 ) {
        for ( int k =  0; k < totalParts; k++) {
          strip.setPixelColor(i + q + (k * led), Wheel( (i + j) % 255)); //turn every third pixel on
        }
      }
      strip.show();
      delay(wait);
      for (int i = 0 ; i < led; i = i + 3 ) {
        for ( int k =  0; k < totalParts; k++) {
          strip.setPixelColor(i + q + (k * led), 0);  //turn every third pixel on
        }
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

// Fill the dots one after the other with a color
void colorWipeByPart3Strips(Adafruit_NeoPixel &strip1, Adafruit_NeoPixel &strip2, Adafruit_NeoPixel &strip3, uint8_t totalParts, uint32_t color, uint8_t wait) {
  int led = strip.numPixels() / totalParts;
  for (uint16_t i = 0; i < led; i++) {
    for (uint16_t j =  0; j < totalParts; j++) {
      strip1.setPixelColor(i + (j * led), color);
      strip2.setPixelColor(i + (j * led), color);
      strip3.setPixelColor(i + (j * led), color);
    }
    strip1.show();
    strip2.show();
    strip3.show();
    delay(wait);
  }
}

void colorWipeByPart4Strips(Adafruit_NeoPixel &strip1, Adafruit_NeoPixel &strip2, Adafruit_NeoPixel &strip3, Adafruit_NeoPixel &strip4, uint8_t totalParts, uint32_t color, uint8_t wait) {
  int led = strip.numPixels() / totalParts;
  for (uint16_t i = 0; i < led; i++) {
    for (uint16_t j =  0; j < totalParts; j++) {
      strip1.setPixelColor(i + (j * led), color);
      strip2.setPixelColor(i + (j * led), color);
      strip3.setPixelColor(i + (j * led), color);
      strip4.setPixelColor(i + (j * led), color);
    }
    strip1.show();
    strip2.show();
    strip3.show();
    strip4.show();
    delay(wait);
  }
}

void setColorAndFadeOut(Adafruit_NeoPixel &strip, uint8_t totalParts, uint32_t color1, uint32_t color2, uint8_t wait) {
  setColor(strip, color1);
  int led = strip.numPixels() / totalParts;
  for (uint16_t i = 0; i < led; i++) {
    for (uint16_t j =  0; j < totalParts; j++) {
      strip.setPixelColor(i + (j * led), color2);
    }
    strip.show();
    delay(wait);
  }
}

void setColorAndFadeOut(uint8_t totalParts, uint32_t color1, uint32_t color2, uint32_t color3, uint8_t wait) {
  setAllOthersStrips(color1);

  int ledsToLightNum = 110;
  int led = ledsToLightNum / totalParts;
  int led2 = 0.2 * 110;
  for (uint16_t i = 0; i < led; i++) {
    for (uint16_t j =  0; j < totalParts; j++) {
      letsStrip.setPixelColor(i + (j * led), color2);
      goStrip.setPixelColor(i + (j * led), color2);
      //      dancingStrip.setPixelColor(i + (j * led), color2);
      strip.setPixelColor(i + (j * led) - 120, color2);
      wannaStrip.setPixelColor(i + (j * led), color2);
      withStrip.setPixelColor(i + (j * led), color2);
      youStrip.setPixelColor(i + (j * led), color2);
      allStrip.setPixelColor(i + (j * led), color2);
      nightStrip.setPixelColor(i + (j * led), color2);

    }
    
    if(i == led2) {
      setColor(dancingStrip, color3); // all
    }
    
    letsStrip.show();
    goStrip.show();
    strip.show();
    wannaStrip.show();
    withStrip.show();
    youStrip.show();
    allStrip.show();
    nightStrip.show();
    delay(wait);
  }
  setColor(dancingStrip, color2); // all
  
}

void setAllOthersStrips(uint32_t color)  {
  setColor(nightStrip, color); // all
  setColor(wannaStrip, color); // all
  setColor(letsStrip, color); // all
  setColor(allStrip, color); // all
  setColor(withStrip, color); // all
  setColor(youStrip, color); // all
  setColor(goStrip, color); // all
  setColor(strip, color); // all
}
