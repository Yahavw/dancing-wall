# Dancing-Wall
This is an Arduino based project, which build for a display in the Midburn festival.
Link to the display video - https://youtu.be/SkQUKy4PR0A

The arduino play the led lights and the pc(python) play the audio track. The main program start when it trigger by any input(sensor, button etc).
The ardiuno recieve the input and then send a signal to the pc, then waiting for the pc to return a signal, like an "hand shake", then they both start to play. 

The project made with Arduino Mega because it support big amount of leds. You can decrease the strips length and use any other Arduino.

# Running
After uploading the program to the Ardiuno device, connect the Arduino to the pc you that will play the audio and run the python script.

#Prerequisities
Arduino and Python 
Install Adafruit_NeoPixel Library - https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation
Install pygame - http://www.pygame.org/wiki/GettingStarted


