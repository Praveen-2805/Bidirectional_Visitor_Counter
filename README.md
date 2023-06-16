# Bidirectional Visitor Counter using AT89S52 Controller

The Bidirectional Visitor Counter project utilizes an AT89S52 microcontroller to count the number of visitors entering and exiting a location. The system employs two IR (Infrared) sensors to detect the presence of individuals and displays the count on an LCD (Liquid Crystal Display).

## Table of Contents
1. [Introduction](#introduction)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Circuit Diagram](#circuit-diagram)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [License](#license)

## Introduction

The Bidirectional Visitor Counter project offers a practical solution for accurately tracking the number of people entering and leaving a specific area. By implementing two IR sensors placed at the entrance and exit points, the system can sense the presence of individuals and increment or decrement the visitor count accordingly. The count is then displayed on an LCD, providing real-time monitoring.

## Hardware Requirements

To build the Bidirectional Visitor Counter, you will need the following components:

- AT89S52 microcontroller
- Two IR sensors
- 16x2 LCD display
- Crystal oscillator (11.0592 MHz)
- Capacitors (33pF and 10µF)
- Resistors (10kΩ and 220Ω)
- Pushbuttons (for reset and control)
- Breadboard or perfboard
- Jumper wires

## Software Requirements

The following software tools are required for setting up the project:

- Keil uVision IDE (Integrated Development Environment)
- AT89S52 microcontroller library for Keil uVision

## Circuit Diagram

   Refer the Files

## Installation

1. Connect the components according to the circuit diagram.
2. Install the Keil uVision IDE by following the official instructions for your operating system.
3. Download and install the AT89S52 microcontroller library for Keil uVision from a reliable source.
4. Clone or download the project code from the repository.
   - If using Git, run the following command:
     ```
     git clone <repository-url>
     ```
   - Alternatively, download the code as a ZIP file and extract it to a local directory.

## Usage

1. Open the Keil uVision IDE and navigate to the project folder.
2. Open the project file (`.uvproj`) in the IDE.
3. Build the project by clicking on the appropriate build button in the IDE.
4. Connect the AT89S52 microcontroller to your computer using a programmer.
5. Flash the compiled code onto the microcontroller using the programming tool supported by the IDE.
6. Connect the circuit to a power source.
7. The visitor count should now be displayed on the LCD.
8. Test the system by passing through the IR sensors and observe the count change accordingly.

## Contributing

Contributions to this project are welcome! If you find any issues or have ideas for improvements, please submit an issue or a pull request in the project's repository.

## License

The Bidirectional Visitor Counter project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Please refer to the `LICENSE` file for more information.
