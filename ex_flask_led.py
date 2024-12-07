from flask import Flask
import RPi.GPIO as GPIO

app = Flask(__name__)

LED_PIN = 21

# set mode
GPIO.setmode(GPIO.BCM)
## led
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(LED_PIN, GPIO.LOW)

@app.route("/")
def flask():
    return "hello flask"

@app.route("/ledon")
def ledOn():
    GPIO.output(LED_PIN, GPIO.HIGH)
    return "<h1>LED ON</h1>";

@app.route("/ledoff")
def ledOff():
    GPIO.output(LED_PIN, GPIO.LOW)
    return "<h1>LED OFF</h1>";

if __name__ == "__main__":
    app.run(host = "0.0.0.0", port = "8080")
