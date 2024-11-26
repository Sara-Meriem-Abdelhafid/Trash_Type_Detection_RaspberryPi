
// Define pin connections for L298N motor driver
//#define enA A15
int out1 = 8;
int out2 = 9;
int out3 = 10;
int out4 = 11;
//#define enB A14

int steps = 200; // You can adjust this value for the number of steps
int Speed = 10000;         // Motor speed in steps per second
//int minSpeed = 100;            // Minimum motor speed in steps per second
//int maxSpeed = 1000;           // Maximum motor speed in steps per second


void setup() {
  // Set the motor control pins as outputs
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  
  // Set enable pins as inputs
  //pinMode(enA, INPUT);
  //pinMode(enB, INPUT);
}

void loop() {
  // Read analog values from enA and enB
  /*int speedA = analogRead(enA);
  int speedB = analogRead(enB);

  // Map analog values to motor speed
  int motorSpeed = map((speedA + speedB) / 2, 0, 1023, minSpeed, maxSpeed);
*/



  // Rotate the motor in one direction
  rotateMotor(steps, Speed);

  delay(1000);  // Pause for a second

  // Rotate the motor in the opposite direction
  rotateMotor(-steps, Speed);

  delay(1000);  // Pause for a second
}
/*
void moveStepper(int steps, int stepDelay) {
  for (int y = steps; y > 0; y--) {
    // Set the motor control pins based on the provided sequence
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
    delay(stepDelay);

    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
    delay(stepDelay);

    // ... Repeat for the remaining steps with the appropriate sequence

    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
    delay(stepDelay);
  }
}
*/
// Function to rotate the motor
void rotateMotor(int steps, int speed) {
  // Set the direction (clockwise or counterclockwise)
  if (steps > 0) {
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
  } else {
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
    steps = -steps;  // Make steps positive for the loop
  }

  // Set motor speed
  int delayTime = 1000 / speed;

  // Step the motor
  for (int i = 0; i < steps; i++) {
    digitalWrite(out1, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(out1, LOW);
    delayMicroseconds(delayTime);

    digitalWrite(out2, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(out2, LOW);
    delayMicroseconds(delayTime);

    digitalWrite(out3, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(out3, LOW);
    delayMicroseconds(delayTime);

    digitalWrite(out4, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(out4, LOW);
    delayMicroseconds(delayTime);
  }
}