![logo](https://github.com/user-attachments/assets/cb173f37-f937-4da2-b989-d094c1281e8a)

# Central Controller for Wireless Devices

This repository contains the code and documentation for the central controller, a crucial component of the wireless smart home system. Built on an ESP32 (NodeMCU), the controller acts as a bridge between the wireless sensors and the backend server. It collects data from the sensors and transmits it to an MQTT broker, enabling backend systems to process and store the data in a database.

## Features

- **Wireless Data Reception**: Receives temperature and humidity data from the thermometer devices via nRF24L01.
- **MQTT Integration**: Transmits the received data to an MQTT broker for further processing.
- **Centralized Data Handling**: Facilitates easy integration with smart home systems and backend databases.

## Hardware Components

1. **ESP32 (NodeMCU)**: Handles data processing and communication with the MQTT broker.
2. **nRF24L01 Module**: Enables wireless reception of data from thermometer sensors.

## How It Works

1. **Data Reception**: The controller listens for data packets sent by the thermometer devices via the nRF24L01 module.
2. **MQTT Transmission**: Upon receiving data, the ESP32 sends it to a configured MQTT broker.
3. **Backend Integration**: The backend system subscribes to the MQTT topics, processes the incoming data, and stores it in a database.

## MQTT Communication

- **Broker**: The MQTT broker is hosted on a VPS server.
- **Topics**: The controller publishes temperature and humidity data under specific topics (e.g., `sensors/thermometer`).

## Installation and Setup

1. Clone this repository:
   ```sh
   git clone https://github.com/kaczorowskid/smart-home-devices.git
   cd smart-home-devices/main-board
   ```
2. Open the provided code in your IDE (e.g., VS Code, Arduino IDE, or PlatformIO).
3. Configure the following in the code:
   - WiFi credentials for connecting to your network.
   - MQTT broker details (IP, and topics).
4. Upload the code to the ESP32 (NodeMCU).
5. Connect the nRF24L01 module to the ESP32 as per the provided schematic.
6. Power the device and verify connectivity with the thermometer sensors and MQTT broker.

## Notes

- Ensure the nRF24L01 module is powered appropriately; consider using a decoupling capacitor for stable voltage.
- Confirm that the MQTT broker is properly configured on your VPS.
- The system can handle multiple thermometer devices, making it scalable for larger setups.

## Future Improvements

- Addition of support for controlling window blinds.

## Galerry

![IMG_3591](https://github.com/user-attachments/assets/bded4362-4ea5-4bd6-ba37-d7b3a346d59b)
![IMG_3590](https://github.com/user-attachments/assets/0af189d9-cace-459e-99dd-76c5c7f0d8bc)
