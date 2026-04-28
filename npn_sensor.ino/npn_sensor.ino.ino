#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

const int sensorPin = 2; 

void setup() {
  Serial.begin(9600);
  // INPUT_PULLUP is essential for NPN (sinking) sensors
  pinMode(sensorPin, INPUT_PULLUP); 
  Serial.println("NPN Sensor Ready");
}

void loop() {
  int val = digitalRead(sensorPin);

  // For NPN, LOW typically means "Detected" 
  if (val == LOW) {
    Serial.println("Liquid Detected!");
  } else {
    Serial.println("--- Empty ---");
  }
  
  delay(500);
}
