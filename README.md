# Data-Viz-Bluetooth-Finish-Line Sensor
Finish line sensor that appears to other devices as a Bluetooth keyboard.

## How it works
The finish line sensor unit is built around the Adafruit Feather nRF52 Bluefruit LE- nRF52832 Microcontroller, and a Sharp GP2Y0A02YK long range distance sensor.  The microcontroller is configured to appear as a Bluetooth keyboard to other devices.  When someone passes the finish line sensor, a letter "a" keypress is transmitted. The keypress is only sent once.  A subsequent keypress only happens when someone has moved-off the sensor and then crosses it again. Though the max range of the Sharp distance sensor is 5 ft. (150 cm), the operating range has been attenuated to work reliably in a 4 ft. (121 cm) wide lane.

## Setup

Ideally, the sensor unit should be placed so that it is aimed somewhere between the lower waist and upper torso of the runners.  The sensor unit should also be perpendicular to the run lane.  Make sure the run lane is a well defined.  Use a tape-line and make sure the run lane is no wider than 4 ft. It is suggested that a sport cone be placed just outside of the run lane (1-2 ft.) directly across from the sensor, so spectators don't accidently trigger the sensor.

The sensor unit can be powered via USB connection to a computer, USB power adaptor, or with the provided USB battery pack.  When fully charged, the provided USB battery pack will allow the sensor unit to operate for several hours.

## Software

If it is necessary to reprogram the microcontroller, use the Arduino IDE, and install the nRF52 library following the instructions here:

https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/arduino-bsp-setup

Prior to installing the library, it may be neccesary to temporarily disable antivirus software when using Windows.

Lastly, make sure to select the correct board before uploading the code.



