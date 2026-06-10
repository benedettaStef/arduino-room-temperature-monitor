# Arduino Room Temperature Monitor

This project is a simple room temperature monitoring system built with **Arduino UNO**, an analog temperature sensor, and a **16x2 I2C LCD display**.
The system reads the temperature in real time, converts the analog value into degrees Celsius, and displays both the temperature and the room status on the LCD screen.
Depending on the detected temperature, the system shows one of the following states:
- `COLD`
- `OK`
- `HOT`
When the temperature is higher than 25°C, the built-in Arduino LED turns on as a visual warning.

---

## Features

- Real-time temperature reading
- Analog sensor data acquisition
- Conversion from analog signal to Celsius degrees
- LCD I2C display output
- Serial Monitor output
- Automatic room temperature status classification
- Built-in LED activation when the temperature is too high

---

## Components Used

- Arduino UNO
- Analog temperature sensor
- 16x2 LCD display with I2C module
- Jumper wires
- Breadboard or online simulator

---

## Circuit Connections

| Component | Arduino Pin |
|---|---|
| Temperature Sensor VCC | 5V |
| Temperature Sensor GND | GND |
| Temperature Sensor OUT | A0 |
| LCD I2C VCC | 5V |
| LCD I2C GND | GND |
| LCD I2C SDA | A4 |
| LCD I2C SCL | A5 |
| Built-in LED | Pin 13 |

---

## How It Works

The Arduino reads the analog value from the temperature sensor connected to pin `A0`.
The analog value is first converted into millivolts and then into Celsius degrees using the following logic:
```cpp
tempMV = tempRaw * 5000.0 / 1023.0;
tempC = (tempMV / 10.0) - 50.0;# Monitoraggio Temperatura Ambiente con Arduino
'''
---

## Screenshot

(images/sim1.png)
(images/sim2.png)
(images/sim3.png)

---

## Code

The source code is available in the file:

```text
monitor_temperatura.ino
