
from machine import Pin, PWM
from time import sleep

# Define pins
ENA_PIN1 = 27  # The Raspberry Pi Pico pin GP27 connected to the ENA pin of L298N
IN1_PIN1 = 28  # The Raspberry Pi Pico pin GP29 connected to the IN1 pin of L298N
IN2_PIN1 = 19  # The Raspberry Pi Pico pin GP19 connected to the IN2 pin of L298N

ENA_PIN2 = 22  # The Raspberry Pi Pico pin GP27 connected to the ENA pin of L298N
IN1_PIN2 = 26  # The Raspberry Pi Pico pin GP29 connected to the IN1 pin of L298N
IN2_PIN2 = 18  # The Raspberry Pi Pico pin GP19 connected to the IN2 pin of L298N

# Initialize pins
ena1 = PWM(Pin(ENA_PIN1))  # PWM for speed control
ena1.freq(1000)  # Set frequency to 1kHz for PWM
ena2 = PWM(Pin(ENA_PIN2))  # PWM for speed control
ena2.freq(1000)  # Set frequency to 1kHz for PWM

in1 = Pin(IN1_PIN1, Pin.OUT)
in2 = Pin(IN2_PIN1, Pin.OUT)
in3 = Pin(IN1_PIN2, Pin.OUT)
in4 = Pin(IN2_PIN2, Pin.OUT)

def set_motor_speed(speed):
    ena1.duty_u16(int(speed * 65535 / 255))  # Convert 0-255 speed to 0-65535 for PWM
    ena2.duty_u16(int(speed * 65535 / 255))  # Convert 0-255 speed to 0-65535 for PWM

def motorL_forward():
    in1.value(1)
    in2.value(0)
    
def motorR_forward():    
    in3.value(1)
    in4.value(0)

def motorL_backward():
    in1.value(0)
    in2.value(1)
    
def motorR_backward():    
    in3.value(0)
    in4.value(1)

def motorS_stop():
    in1.value(0)
    in2.value(0)
    in3.value(0)
    in4.value(0)

while True:

    motorL_forward()
    motorR_forward()
   # sleep(1)
    
    for speed in range(256):
        set_motor_speed(speed)
        sleep(0.01)

    sleep(1)
    
    motorS_stop()
    sleep(2)

    # circle right
    motorL_forward()
    motorR_backward()
    # sleep(1)
    
    for speed in range(256):
        set_motor_speed(speed)
        sleep(0.01)

    sleep(1.26)
    
    motorS_stop()
    sleep(2)


    #back up
    motorL_backward()
    motorR_backward()
    sleep(1)

    for speed in range(255, -1, -1):
        set_motor_speed(speed)
        sleep(0.01)

    motorS_stop()
    sleep(1)

    # circle left
    motorL_backward()
    motorR_forward()
   # sleep(1)
    
    for speed in range(256):
        set_motor_speed(speed)
        sleep(0.01)

    sleep(1.36)
    
    motorS_stop()
    sleep(2)




