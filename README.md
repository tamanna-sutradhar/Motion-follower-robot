# 🤖 Autonomous Motion Follower Robot

An Arduino-based smart robot designed to navigate autonomously by tracking motion and measuring obstacles using an ultrasonic sensor and infrared (IR) line/obstacle sensors. 

---

## 🛠️ Components Used
* **Microcontroller:** Arduino Uno R3
* **Motor Driver:** L293D IC (Breadboard setup)
* **Distance Sensor:** Ultrasonic Sensor (HC-SR04)
* **Proximity/Direction Sensors:** IR Sensors (Left and Right)
* **Actuators:** 4x DC Toy Motors (paired left and right)
* **Power Source:** 9V Battery pack
* **Programming Language:** C++ (Arduino IDE)

---

## 📌 Circuit Connections

| Component | Pin / Terminal | Connected To (Arduino / L293D) |
| :--- | :--- | :--- |
| **Ultrasonic Sensor (HC-SR04)** | VCC | 5V |
| | Trig | Arduino Pin `A5` |
| | Echo | Arduino Pin `A4` |
| | GND | GND |
| **Left IR Sensor** | OUT | Arduino Pin `A0` |
| **Right IR Sensor** | OUT | Arduino Pin `A1` |
| **L293D Motor Driver** | VCC1 (Pin 16) | 5V |
| | VCC2 (Pin 8) | External 9V Battery (+) |
| | GND (Pins 4, 5, 12, 13) | Common Ground (GND) |
| | Outputs (Pins 3, 6, 11, 14) | DC Motors (Paired Left/Right) |

---

## ⚙️ How It Works
1. **Distance Monitoring:** The HC-SR04 ultrasonic sensor continuously pings the environment to measure distance (`sonar.ping_cm()`).
2. **Path Correction:** The left and right IR sensors read surface or directional cues to help steer the robot.
3. **Behavioral Logic:**
   * **Forward:** When the path is clear within range and both IR sensors detect alignment.
   * **Turning:** If one IR sensor triggers a change, the motor driver reverses polarity on one side to pivot the robot left or right.
   * **Reverse / Stop:** If an object gets too close or path conditions drop, the robot backs up or halts motion.

---

## 📂 Repository Structure
```text
Motion-Follower-Robot/
├── code/
│   └── motion_follower.ino   # Main C++ Arduino sketch
├── assets/
│   └── circuit-diagram.png   # Breadboard schematic layout
└── README.md
