//#include "arduino_secrets.h"
//#include <WiFiNINA.h>
#include <SPI.h>
//#include "Cloud.h"

int ledState = LOW;                       //ledState used to set the LED
//unsigned long previousMillisInfo = 0;     //will store last time Wi-Fi information was updated
//unsigned long previousMillisLED = 0;      // will store the last time LED was updated
const int intervalInfo = 5000;            // interval at which to update the board information


// Data setup for Measurement 
const int sensorPin5 = A5; // ADC pin to read V_in, A5
const int sensorPin4 = A4; // ADC pin to read V_in, A5
const int sensorPin3 = A3; // ADC pin to read V_in, A5

// Make sure no connection in A0-A1 when using serial port with PC //

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  //while (!Serial);
  //Wifi_Init();
  // set the LED as output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // ArduinoCloud.update();
  // Code for LED blinking // To check connection status
  unsigned long currentMillisLED = millis();
  // measure the signal strength and convert it into a time interval
  int intervalLED = WiFi.RSSI() * -10;
 
  // check if the time after the last blink is bigger the interval 
  if (currentMillisLED - previousMillisLED >= intervalLED) {
    previousMillisLED = currentMillisLED;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN, ledState);
  } 
  
  // Code for measurement
  // Read input every 0.5 second //
  delay(500);
  int sensorValue5 = analogRead(sensorPin5);
  int sensorValue4 = analogRead(sensorPin4);
  int sensorValue3 = analogRead(sensorPin3);
  // Convert the analog reading to voltage
  int vol5 = (sensorValue5 / 1023.0) * 3.3; // 3.3V reference voltage
  int vol4 = (sensorValue4 / 1023.0) * 3.3; // 3.3V reference voltage
  int vol3 = (sensorValue3 / 1023.0) * 3.3; // 3.3V reference voltage
  // Print the voltages to the serial monitor
  Serial.print("V");
  Serial.println(vol5, 2); // Print with 2 decimal places
  Serial.print("B");
  Serial.println(vol4, 2); // Print with 2 decimal places
  Serial.print("N");
  Serial.println(vol3, 2); // Print with 2 decimal places
  // Can do calculation now, but where current ????

}