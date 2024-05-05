#include <Servo.h>

const int micPin = 2; // Digital input pin for the microphone module
const int servoPin = 3; // PWM pin for the servo motor
const int threshold = 500; // Adjust threshold as needed
const int clapCountThreshold = 2; // Number of claps required to trigger servo motion

Servo servo; // Create a servo object
int clapCount = 0; // Variable to count the number of claps
bool servoTriggered = false; // Flag to indicate if servo motion is triggered
int servoPosition = 5; // Variable to store the current servo position

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(micPin, INPUT); // Set the microphone pin as input
  servo.attach(servoPin); // Attach servo to its pin
  servo.write(servoPosition); // Set initial servo position
}

void loop() {
  int micValue = digitalRead(micPin); // Read digital value from microphone module
  if (micValue == HIGH) { // If sound is detected (micValue is HIGH)
    Serial.println("Clap detected!"); // Print message to serial monitor
    clapCount++; // Increment clap count
    delay(85); // Debounce delay to avoid multiple detections for a single clap

    // Check if required number of claps are detected and servo is not already triggered
    if (clapCount >= clapCountThreshold && !servoTriggered) {
      Serial.println("Claps detected! Triggering servo motion...");
      // Toggle servo position between 5 and 56 degrees
      servoPosition = (servoPosition == 5) ? 56 : 5;
      servo.write(servoPosition); // Set servo to new position
      servoTriggered = true; // Set servo triggered flag
    }
  }

  // If servo motion is triggered
  if (servoTriggered) {
    // Do nothing until two more claps are detected
    while (clapCount < clapCountThreshold + 2) {
      int micValue = digitalRead(micPin); // Read digital value from microphone module
      if (micValue == HIGH) { // If sound is detected (micValue is HIGH)
        Serial.println("Clap detected!"); // Print message to serial monitor
        clapCount++; // Increment clap count
        delay(85); // Debounce delay to avoid multiple detections for a single clap
      }
    }
    
    // Two more claps detected, reset clap count and servo triggered flag
    clapCount = 0;
    servoTriggered = false;
  }
}
