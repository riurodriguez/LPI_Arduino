// Joystick Pins
int joystickX = A0;  // X-axis (left-right)
int joystickY = A1;  // Y-axis (up-down)

// LED Pins
int ledLeft = 8;
int ledRight = 9;
int ledUp = 10;
int ledDown = 11;

// Variables to store joystick values
int xValue, yValue;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  
  // Start serial communication (for debugging)
  Serial.begin(9600);
}

void loop() {
  // Read the values from the joystick
  xValue = analogRead(joystickX);
  yValue = analogRead(joystickY);
  
  // Debugging: Print joystick values to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.println(yValue);

  // Control LEDs based on joystick position

  // Left and Right Control (X-axis)
  if (xValue < 400) {
    // Move left: Light up left LED
    digitalWrite(ledLeft, HIGH);
    digitalWrite(ledRight, LOW);
  } 
  else if (xValue > 600) {
    // Move right: Light up right LED
    digitalWrite(ledRight, HIGH);
    digitalWrite(ledLeft, LOW);
  } 
  else {
    // No horizontal movement
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
  }

  // Up and Down Control (Y-axis)
  if (yValue < 400) {
    // Move up: Light up up LED
    digitalWrite(ledUp, HIGH);
    digitalWrite(ledDown, LOW);
  } 
  else if (yValue > 600) {
    // Move down: Light up down LED
    digitalWrite(ledDown, HIGH);
    digitalWrite(ledUp, LOW);
  } 
  else {
    // No vertical movement
    digitalWrite(ledUp, LOW);
    digitalWrite(ledDown, LOW);
  }

  delay(100);  // Small delay to avoid flickering
}
