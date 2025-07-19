// IR Sensors
#define leftIR 2
#define rightIR 3

// Ultrasonic Sensor
#define trigPin 9
#define echoPin 10

// Motor Driver Pins
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

long duration;
int distance;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leftValue = digitalRead(leftIR);
  int rightValue = digitalRead(rightIR);
  
  // Measure distance using Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 10) {
    stopMotors();  // Too close
  }
  else if (distance >= 10 && distance <= 30) {
    // Decide direction based on IR sensors
    if (leftValue == 1 && rightValue == 1) {
      moveForward();
    }
    else if (leftValue == 1 && rightValue == 0) {
      turnLeft();
    }
    else if (leftValue == 0 && rightValue == 1) {
      turnRight();
    }
    else {
      stopMotors(); // Lost sight of person
    }
  }
  else {
    stopMotors();  // Person is too far
  }

  delay(100);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
