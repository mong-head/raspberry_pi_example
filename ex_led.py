import RPi.GPIO as GPIO
import time

# set mode
GPIO.setmode(GPIO.BCM)
## led
GPIO.setup(21, GPIO.OUT)
GPIO.setup(21, GPIO.LOW)
## push button
GPIO.setup(26, GPIO.IN)

##
try:
    while 1:
        if GPIO.input(26) == GPIO.HIGH:
            GPIO.output(21, GPIO.HIGH)
        else :
            GPIO.output(21, GPIO.LOW)

except KeyboardInterrupt:
    pass

GPIO.cleanup()