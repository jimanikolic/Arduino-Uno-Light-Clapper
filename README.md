# Clapper System with Arduino Uno

## Components Needed:
- Arduino Uno board
- Microphone module
- Servo motor
- Jumper wires

## Wiring Steps:

### Connect Microphone Module:
1. Connect the digital output pin of the microphone module to digital pin 2 (micPin) on the Arduino Uno.
2. Connect the ground (GND) pin of the microphone module to any ground (GND) pin on the Arduino Uno.
3. Optionally, connect the 5V pin of the microphone module to the 5V pin on the Arduino Uno if your microphone module requires power.

### Connect Servo Motor:
1. Connect the signal (SIG) pin of the servo motor to digital pin 3 (servoPin) on the Arduino Uno.
2. Connect the power (VCC) pin of the servo motor to the 5V pin on the Arduino Uno.
3. Connect the ground (GND) pin of the servo motor to any ground (GND) pin on the Arduino Uno.

### Power Supply:
- Connect the Arduino Uno to your computer using a USB cable or to a battery box.

---

## Further Instructions:
- Follow the provided Arduino code to program your Uno board.
- Ensure that the microphone module is properly detecting claps.
- Adjust the threshold values in the code as needed for optimal performance.
- Test the system to ensure proper functionality.

---

## Code:
You can find the Arduino code for this project in the `clapper.ino` file.
