
from machine import Pin, PWM
from time import sleep

# Define pins
ENA_PIN = 27  # The Raspberry Pi Pico pin GP27 connected to the ENA pin of L298N
IN1_PIN = 28  # The Raspberry Pi Pico pin GP29 connected to the IN1 pin of L298N
IN2_PIN = 19  # The Raspberry Pi Pico pin GP19 connected to the IN2 pin of L298N

# Initialize pins
ena = PWM(Pin(ENA_PIN))  # PWM for speed control
ena.freq(1000)  # Set frequency to 1kHz for PWM
in1 = Pin(IN1_PIN, Pin.OUT)
in2 = Pin(IN2_PIN, Pin.OUT)

def set_motor_speed(speed):
    ena.duty_u16(int(speed * 65535 / 255))  # Convert 0-255 speed to 0-65535 for PWM

def motor_forward():
    in1.value(1)
    in2.value(0)

def motor_backward():
    in1.value(0)
    in2.value(1)

def motor_stop():
    in1.value(0)
    in2.value(0)

while True:
    motor_forward()
    for speed in range(256):
        set_motor_speed(speed)
        sleep(0.01)

    sleep(1)
    
    
    motor_stop()
    sleep(2)

    motor_backward()
    sleep(1)

    for speed in range(255, -1, -1):
        set_motor_speed(speed)
        sleep(0.01)

    motor_stop()
    sleep(1)





