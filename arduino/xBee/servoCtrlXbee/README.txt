Codebase for remote control of servo motors over xbee wireless communication. Currently runnong on 2 UNO boards and using a gyroscope to generate the data sent over serial wireless.

ATM servo movement is triggered by string constants only, algoritm to scale input from gyroscope into proper smoothed servo control is still being developed.

Note issues with uploading code to boards unless xbee units are disconnected, as upload seems to hang when left plugged in.

Vaiants of movement paradigms to include GPS input data, true gyrscope scaled movement, and modified vehicle control of steering, throttle, brakes in both 2 and 3 dimensions.
