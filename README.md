# human-following-robot
A smart Arduino-based robot that follows a human using an ultrasonic sensor for distance detection and IR sensors for directional tracking. Powered by four DC motors and an L298N driver, it intelligently moves, turns, and stops based on sensor input.


# 🤖 Human Following Robot (Arduino-Based)

A smart human-following robot built using **Arduino**, **ultrasonic sensor**, and **two IR sensors**. This robot can follow a human or object by sensing distance and direction intelligently. It uses a combination of **IR sensors for direction detection** and an **ultrasonic sensor for distance control**, powered by **4 DC motors and an L298N motor driver**.

---

## 📷 Project Demo

![IMG-20240914-WA0002](https://github.com/user-attachments/assets/6ad486ff-5e15-487b-acde-ffe0cd267375)

---

## 🛠️ Components Used

| Component               | Quantity |
|------------------------|----------|
| Arduino Uno / Nano / Mega | 1        |
| Ultrasonic Sensor (HC-SR04) | 1        |
| IR Sensors (TCRT5000 or similar) | 2        |
| L298N Motor Driver Module     | 1        |
| DC Motors                    | 4        |
| Chassis + Wheels            | 1 set    |
| Battery (12V recommended)   | 1        |
| Jumper Wires & Breadboard (optional) | As needed |

---

<img width="3160" height="1964" alt="image" src="https://github.com/user-attachments/assets/beb5dcf3-fec2-4087-8e77-1c13415a746e" />

## ⚙️ Working Principle

- The **ultrasonic sensor** constantly measures the distance to the person/object.
- If the person is within a specific range (10–30 cm), the robot moves toward them.
- **Left and right IR sensors** detect which direction the object is in and help steer the robot accordingly.
- The robot **stops** when the person is too close or too far.

---

## 🧠 Logic Flow

| Condition                        | Action         |
|----------------------------------|----------------|
| Distance < 10 cm                 | Stop           |
| Distance 10–30 cm & IRs detect object in center | Move Forward |
| IR Left = 1, Right = 0           | Turn Left      |
| IR Left = 0, Right = 1           | Turn Right     |
| No IR detection                  | Stop           |
| Distance > 30 cm                 | Stop           |

---

## 🔌 Wiring Summary

### IR Sensors:
- Left IR → D2  
- Right IR → D3  

### Ultrasonic:
- Trig → D9  
- Echo → D10  

### Motor Driver (L298N):
- IN1 → D4  
- IN2 → D5  
- IN3 → D6  
- IN4 → D7  
- ENA & ENB → 5V  
- VCC → Battery +12V  
- GND → Arduino GND and Battery –  

---

## 🧾 Code

The complete code is in (./_code.ino).  
Make sure to upload using Arduino IDE with the correct board and port selected.

---

## 🚀 How to Run

1. Clone the repository or download the ZIP.
2. Open `robot_code.ino` in Arduino IDE.
3. Connect your Arduino board and upload the code.
4. Assemble your robot with proper wiring.
5. Power the circuit using a 12V battery.
6. Place a person or object with dark clothing in front of the sensors and watch the robot follow!

---

## 📈 Future Improvements

- Add Servo-mounted Ultrasonic for scanning.
- Add Bluetooth control fallback.
- Use PID to maintain constant distance.
- Integrate camera for vision-based following.

---

## 👨‍💻 Author

**Prajwal .P**  
Electronics and Communication Engineering  

---

## 📜 License

This project is open-source and free to use under the MIT License.

