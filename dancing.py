#!/usr/bin/python
import serial
import time

import pygame

# Init pygame for playing the audio
pygame.init()
pygame.mixer.init()
pygame.mixer.music.load('dancing-full.wav')


def wait_for_arduino():
    connect = None
    while(not(connect)) :
        try:
            ard = serial.Serial(port,9600,timeout=5)
        except: # catch *all* exceptions
            for event in pygame.event.get():
                 if event.type == pygame.KEYDOWN:
                    print ("Exiting")
                    exit()

            print ("Waiting to Arduino");
            time.sleep(2) # wait to Arduino
        else:
          connect = True
    return ard


#The following line is for serial over GPIO
port = '/dev/tty.usbmodem1451'


time.sleep(2) # wait for Arduino


ard = wait_for_arduino()


while (True):

    try:
        # Serial read section
        msg = ard.read(ard.inWaiting()) # read all characters in buffer
    except: # catch *all* exceptions
        pygame.mixer.music.stop();
        ard = wait_for_arduino()
        time.sleep(2) # wait for Arduino

    # Wait for message from arduino to start playing
    if msg == '1':
        print ("Message from arduino: ");
        print (msg);
        # If its already playing do nothing
        if (not pygame.mixer.music.get_busy()) :
            pygame.mixer.music.play();

        sendValue = '0';
        ard.write(sendValue);

    elif msg == '0':
        pygame.mixer.music.stop();

    try:
       ard.flush()
    except: # catch *all* exceptions
        time.sleep(1) # wait for Arduino


    time.sleep(0.1)

else:
    print ("Exiting")
exit()

