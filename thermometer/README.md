![logo](https://github.com/user-attachments/assets/cb173f37-f937-4da2-b989-d094c1281e8a)

# Wireless Thermometer

This repository contains the code and documentation for a wireless thermometer device built using an Arduino Pro Mini. The thermometer measures temperature and humidity every 10 minutes and transmits the data wirelessly to a central controller. This device is designed to be energy-efficient, battery-powered, and seamlessly integrate into a smart home system.

## Features

- **Temperature Measurement**: Provides accurate temperature readings using the DHT11 sensor.
- **Humidity Measurement**: Measures the surrounding air's relative humidity.
- **Wireless Communication**: Transmits data wirelessly using the nRF24L01 module.
- **Battery-Powered**: Operates on a battery for maximum portability and flexibility.
- **Energy Efficiency**: Utilizes deep sleep mode between measurements to minimize power consumption.

## Hardware Components

1. **Arduino Pro Mini (3.3V)**: The core microcontroller for managing sensor data and wireless communication.
2. **nRF24L01 Module**: Ensures reliable wireless communication with the central controller.
3. **DHT11 Sensor**: Detects temperature and humidity in the surrounding environment.

## How It Works

1. **Wake-Up**: The Arduino wakes up every 10 minutes using a watchdog timer.
2. **Data Collection**: The DHT11 sensor collects temperature and humidity data.
3. **Data Transmission**: The nRF24L01 module sends the collected data to the central controller.
4. **Sleep Mode**: The device enters deep sleep mode to conserve battery power until the next measurement cycle.

## Energy Efficiency

- The 3.3V Arduino Pro Mini is selected to optimize power consumption.
- LED diodes on the Arduino board are desoldered to further reduce energy usage.
- The nRF24L01 module is configured in power-down mode when not transmitting.

## Installation and Usage

1. Clone this repository:
   ```sh
   git clone https://github.com/kaczorowskid/smart-home-devices.git
   cd smart-home-devices/thermometer
   ```
2. Open the Arduino IDE or Visual Studio Code (PlatformIO extension required) and upload the provided sketch to the Arduino Pro Mini.
3. Connect the DHT11 sensor and nRF24L01 module according to the provided schematic.
4. Power the device with a suitable battery.
5. Set up a compatible receiver with an nRF24L01 module to collect the transmitted data.

## Notes

- Ensure the nRF24L01 module has stable power; use a capacitor if necessary to stabilize the voltage.
- While the DHT11 sensor has some limitations in accuracy and response time, it is sufficient for basic temperature and humidity monitoring.
- A central controller is required to receive and store the transmitted data.

## Future Improvements

- Addition of more advanced sensors to monitor other environmental parameters.
- Implementation of encryption for secure wireless communication.
- Integration with smart home systems for centralized data access and advanced control features.

## Gallery

![IMG_3456](https://github.com/user-attachments/assets/5f22e92c-068e-4250-885f-7c5f42b166e0)
![IMG_3455](https://github.com/user-attachments/assets/66c7fbed-ab88-42ef-a0d6-b5a3e50f8173)
