This is some sample code to run multiple sensors on an arduino mega with a sensor sheild. See Pictures, Note that the wiring for each harness must be swapped around to accommodate the layout of the sheild connections.

At the moment we are powering the mega with both a 9v and 4 AA cells and sampling every few minutes without turning anything off - this is to get a baseline for battery life before we introduce some better control loops to heat up sensors, take readings, then let things settle before taking the next reading.

Ideally we want autonomous operation over a long period of time without requiring resets or more power.

TODOS
add better timing of all sensor readings
add local storage
add wifi or bluetooth
