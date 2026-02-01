# PHN Technology ESP32 Workshop Reference Repository

This repository contains firmware experiments, reference implementations, and collected materials related to my work with the ESP32 platform during a one-day hands-on workshop held at **IIT Guwahati**.

The purpose of this repository is **personal long-term reference**.  
It is not intended to function as workshop material, teaching content, or a guided tutorial.

---

## Context

- **Event Type:** One-day, in-person ESP32 workshop  
- **Duration:** 10:00 AM – 6:00 PM  
- **Team Structure:** Group-based work (two groups per team, three members per group)
- **Prerequisites:** Working knowledge of the C programming language

This repository aggregates reusable code patterns and working configurations that I expect to reuse or extend in larger ESP32-based systems.

---

## Development Environment

- **Target Platform:** ESP32 Dev Module  
- **Framework:** Arduino core for ESP32  
- **IDE:** Arduino IDE  
- **Host OS:** Cross-platform (Windows / macOS / Linux)

All code assumes the Arduino programming model and ESP32 board definitions.

---

## Hardware Used

- ESP32 Dev Module
- Beeper actuator
- Temperature sensor
- RFID sensor
- Breadboard and jumper wires

Hardware-specific assumptions are reflected directly in the code and are not abstracted for general portability.

---

## Repository Focus

This repository includes working examples and partial implementations covering:

- GPIO manipulation (e.g., LED blinking and beeper control)
- Sensor interfacing (temperature and RFID)
- Wi-Fi connectivity on ESP32
- Hosting a browser-accessible dashboard directly on the ESP32
- Monitoring sensor data via a web-based UI
- Remote control of sensors and actuators through HTTP endpoints
- Integration with **ThingSpeak** for cloud-based data visualization and remote access

---

## License

This repository is licensed under the **GNU General Public License v3.0**.  
See the `LICENSE` file in the project root for details.
