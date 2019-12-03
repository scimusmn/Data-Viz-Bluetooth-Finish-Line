# Data-Viz-Bluetooth-Finish-Line Sensor
Finish line sensor that appears to other devices as a Bluetooth keyboard.  When the sensor is triggered, a letter "a" key-press is transmitted.

##How it works##
The finish-line sensor package is built around the Adafruit Feather nRF52 Bluefruit LE - nRF52832 Microcontroller, and a Sharp GP2Y0A02YK long range distance sensor.  The microcontroller is configured to appear as a Bluetooth Keybord to other devices.  When someone passes the finish line, a letter "a" is transmitted via Bluetooth. The keypress is only sent once.  A subsequent keypress ony happens when someone has moved-off the sensor and crosses it again. Though the max range of the Sharp distance sensor is ~ 5 ft. (150 cm), the operating range has been attenuated to work reliably in a 4 ft. (121 cm) wide lane.

