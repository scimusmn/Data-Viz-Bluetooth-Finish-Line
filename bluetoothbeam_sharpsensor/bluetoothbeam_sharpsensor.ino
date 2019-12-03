#include <bluefruit.h>

int adcin = A0; //analog input A0
int adcValue = 0;
int triggerThreshold = 150; //this sets the minimum trigger distance
int releaseThreshold = 100; //threshold value for allowing a new trigger
int debounce = 300; //this sets delay between subsequent triggers
bool triggered = false;

BLEDis bledis;
BLEHidAdafruit blehid;

void setup()
{
  pinMode(17, OUTPUT); // Onboard LED
  Bluefruit.begin();
  // Set max power. Accepted values are: -40, -30, -20, -16, -12, -8, -4, 0, 4
  Bluefruit.setTxPower(4);
  Bluefruit.setName("DataVis_Break");
  Bluefruit.autoConnLed(false);

  // Configure and Start Device Information Service
  bledis.setManufacturer("Adafruit Industries");
  bledis.setModel("Bluefruit Feather 52");
  bledis.begin();

  /* Start BLE HID
     Note: Apple requires BLE device must have min connection interval >= 20m
     ( The smaller the connection interval the faster we could send data).
     However for HID and MIDI device, Apple could accept min connection interval
     up to 11.25 ms. Therefore BLEHidAdafruit::begin() will try to set the min and max
     connection interval to 11.25  ms and 15 ms respectively for best performance.
  */
  blehid.begin();

  /* Set connection interval (min, max) to your perferred value.
     Note: It is already set by BLEHidAdafruit::begin() to 11.25ms - 15ms
     min = 9*1.25=11.25 ms, max = 12*1.25= 15 ms
  */
  /* Bluefruit.setConnInterval(9, 12); */

  // Set up and start advertising
  startAdv();
}

void startAdv(void)
{
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);

  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for the dev name in the advertising packet
  Bluefruit.Advertising.addName();

  /* Start Advertising
     - Enable auto advertising if disconnected
     - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     - Timeout for fast mode is 30 seconds
     - Start(timeout) with timeout = 0 will advertise forever (until connected)

     For recommended advertising interval
     https://developer.apple.com/library/content/qa/qa1931/_index.html
  */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void loop()
{
  adcValue = analogRead(adcin); //get analog value from distance sensor
  if ((adcValue > triggerThreshold) && (!triggered)) {
    triggered = true;
    digitalWrite(17, HIGH); //turn on "sense" indicator LED
    blehid.keyPress('a');
    blehid.keyRelease();
    blehid.keyRelease(); //this is run twice to ensure key has been released
    digitalWrite(17, LOW);
    delay(debounce);
  }
  if ((adcValue  < releaseThreshold) && (triggered))  { //provides hysterisis to prevent 'a' key from repeating
    triggered = false;
  }
}
