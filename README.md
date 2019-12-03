# Data-Viz-Bluetooth-Finish-Line Sensor
Finish line sensor that appears to other devices as a Bluetooth keyboard.  When the sensor is triggered, a letter "a" key-press is transmitted.

## How it works
The finish-line sensor package is built around the Adafruit Feather nRF52 Bluefruit LE - nRF52832 Microcontroller, and a Sharp GP2Y0A02YK long range distance sensor.  The microcontroller is configured to appear as a Bluetooth Keybord to other devices.  When someone passes the finish line, a letter "a" is transmitted via Bluetooth. The keypress is only sent once.  A subsequent keypress ony happens when someone has moved-off the sensor and crosses it again. Though the max range of the Sharp distance sensor is ~ 5 ft. (150 cm), the operating range has been attenuated to work reliably in a 4 ft. (121 cm) wide lane.

## Setup

Ideally, the sensor should be placed so that it is aimed somewhere between the lower waist and upper torso of the runners.  The sensor unit should also be perpendicular to the lane.  Make sure the run lane is a well defined using a tape-line, and is no more than 4ft. wide.  It is suggested that a sport cone be placed just outside of the lane 1-2 ft. directly across from the sensor, so spectators don't accidently trigger the sensor.

The sensor unit can be powered via USB connection to a computer, USB power adaptor, or with the provided USB battery pack.  When fully charged, the provided USB battery pack will allow the sensor unit to operate for several hours.

## Software

If it is necessary to reload the code onto the microcontroller, use the Arduino IDE, and install the nRF52 library following the instructions here:

https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/arduino-bsp-setup

It may be neccesary to temporarily disable antivirus software when installing on Windows.



