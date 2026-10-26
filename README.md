# smartrobot
# 🤖 Smart Robot for Kids

## 📌 Project Overview

The **Smart Robot for Kids** is an interactive, electronics-based robot designed to make learning fun and engaging for children. It uses an ESP32 microcontroller, an IR obstacle detection sensor, a DFPlayer Mini audio module, push buttons, and a MOSFET-controlled motor system.

The robot detects obstacles, stops its motor for safety, and plays an alert sound. It also provides an educational audio experience by allowing children to listen to nursery rhymes and multiplication tables using dedicated push buttons.

## 🎯 Objectives

- To develop an interactive and educational robot for kids.
- To detect obstacles using an IR sensor.
- To automatically stop the motor when an obstacle is detected.
- To play audio files stored on an SD card using the DFPlayer Mini.
- To provide easy access to nursery rhymes and multiplication tables through push buttons.
- To gain practical experience with embedded systems and hardware interfacing.

## 🛠️ Hardware Components

- ESP32 Development Board
- DFPlayer Mini MP3 Player Module
- IR Obstacle Detection Sensor
- Two Push Buttons
- DC Motor
- Logic-Level N-Channel MOSFET
- Speaker
- MicroSD Card
- External Motor Power Supply
- Connecting Wires
- Breadboard or PCB
- Flyback Diode for Motor Protection

## 💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- DFRobotDFPlayerMini Library
- Embedded C++ Programming

## ⚙️ Working Principle

1. **System Initialization:** The ESP32 initializes the IR sensor, push buttons, motor control pin, and DFPlayer Mini.
2. **Obstacle Detection:** The IR sensor continuously monitors the area in front of the robot.
3. **Motor Control:** When an obstacle is detected, the ESP32 switches off the motor through the MOSFET.
4. **Audio Alert:** The DFPlayer Mini plays audio file `0001.mp3` to indicate obstacle detection.
5. **Nursery Rhymes:** Pressing Button 1 plays `0002.mp3`, containing nursery rhymes.
6. **Multiplication Tables:** Pressing Button 2 plays `0003.mp3`, containing multiplication tables.
7. **Automatic Movement:** When the obstacle is removed, the motor turns on again.

## 🔊 SD Card File Structure

Format the microSD card as FAT32 and arrange the audio files as follows:

```text
SD Card/
└── MP3/
    ├── 0001.mp3  # Obstacle alert
    ├── 0002.mp3  # Nursery rhymes
    └── 0003.mp3  # Multiplication tables
```

## 🔌 Main Connections

| Component | ESP32 Pin |
|---|---|
| IR Sensor OUT | GPIO 27 |
| Button 1 | GPIO 25 |
| Button 2 | GPIO 26 |
| MOSFET Gate | GPIO 23 |
| DFPlayer TX | GPIO 16 |
| DFPlayer RX | GPIO 17 |

**Note:** Connect all circuit grounds together. Use an appropriate external power supply for the motor and a suitable logic-level MOSFET. Add a flyback diode across the motor.

## ✨ Features

- Automatic obstacle detection
- Motor cutoff using a MOSFET
- Audio alerts for obstacles
- Button-controlled nursery rhymes
- Button-controlled multiplication tables
- SD card-based audio playback
- ESP32-based embedded control
- Interactive and educational functionality

## 🎓 Applications

- Educational robotics for children
- Basic obstacle detection and avoidance demonstrations
- Interactive learning systems
- Embedded systems and IoT learning projects
- Electronics and robotics laboratory demonstrations

## 🚀 Future Improvements

- Add Bluetooth or Wi-Fi control.
- Add voice commands.
- Integrate ultrasonic sensors for distance measurement.
- Add an LCD or OLED display.
- Include more educational audio files.
- Add rechargeable battery power and improved motor control.

## 📚 Learning Outcomes

This project demonstrates practical implementation of microcontroller programming, sensor interfacing, UART communication, audio playback, digital input handling, and MOSFET-based motor control.

## 👩‍💻 Project Status

**Status:** Hardware project under development.

## 📄 License

This project is intended for educational and learning purposes. A suitable open-source license can be added when the repository is published.

---

**Smart Robot for Kids — Making Learning Interactive Through Robotics! 🤖**


