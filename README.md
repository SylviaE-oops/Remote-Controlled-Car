# Remote-Controlled-Car

## Project Overview
This is a remote-controlled car built using Arduino with line-tracing and IR remote control capabilities. The project demonstrates hands-on experience with electronics, motor control, and Arduino programming, and serves as an educational prototype for robotics and embedded systems.

## Technologies Used
- **Hardware:** Arduino Uno, L298N Motor Driver, IR Receiver, DC Motors, 6V Battery (4x1.5V), Switch, Wheels & Chassis
- **Software:** Arduino IDE, C++
- **Rationale:** Components were chosen for availability, compatibility, and ease of use. The IR receiver was used since Arduino Uno does not have built-in Wi-Fi or Bluetooth.

## Features
- Remote control using an IR receiver
- Motor control via L298N driver
- Basic line-tracing capability (optional to expand)
- Modular wiring for easy debugging and testing

## Project Setup
1. Assemble the chassis and attach the wheels.
2. Connect DC motors to the L298N motor driver.
3. Connect the battery holder to a switch, and the switch to the motor driver.
4. Connect the motor driver to the Arduino Uno.
5. Wire the IR receiver to Arduino.
6. Upload the provided Arduino code using Arduino IDE.
7. Test each component individually, then test full operation.

## Challenges Faced
- Wiring circuits correctly and avoiding short circuits
- Integrating remote control functionality with motor logic
- Overcame challenges by testing each component separately and debugging incrementally

## Learning Outcomes
- Improved understanding of electronics, motor drivers, and Arduino programming
- Developed problem-solving and troubleshooting skills
- Gained practical experience in building a functional embedded system

## Future Improvements
- Upgrade to a higher-voltage battery and more advanced microcontroller
- Add autonomous line-following and obstacle avoidance features
- Explore additional sensors for more advanced robotics projects

## Real-World Applications
- Educational robotics projects
- Prototype vehicles for automation experiments
- Introductory experience in embedded systems and electronics

## License
This project is open-source and free to use for educational purposes.
