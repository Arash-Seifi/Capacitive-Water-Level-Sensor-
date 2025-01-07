# Capacitive-Water-Level-Sensor-
A simple and cost-effective capacitive water level sensor using an Arduino. This project measures the water level in a container by detecting changes in capacitance between two electrodes. It provides a visual indication of the water level using LEDs.

## 1. Problem Statement
Monitoring water levels in storage tanks or containers is crucial in various applications, such as agriculture, domestic water usage, and industrial processes. Traditional mechanical water level sensors are often prone to wear and tear or inaccuracies due to environmental conditions. This project aims to design and implement a low-cost, reliable water level sensor using capacitance measurement. The sensor uses two electrodes to detect water levels by monitoring changes in capacitance as the water level rises.

## 2. Components Used
To build the capacitive water level sensor, the following components were utilized:
![photo_6044130428975170452_y](https://github.com/user-attachments/assets/186dad33-81bd-42ed-88e9-641bc39be43e)

Arduino Board:
  Acts as the brain of the system, measuring charging times and controlling LEDs.
  
Breadboard:
  Facilitates easy connections between components.
  
Jumper Wires:
  Connect various components on the breadboard and Arduino.
  
Two Metal Plates (Electrodes):
  Serve as the sensing element. The capacitance between the plates changes with the water level.
  
10 nF Capacitor:
  Connected in parallel with the electrodes, it determines the charging time based on the water level.
  
220Ω Resistors:
  Connected in series with each LED to limit current and prevent damage to the LEDs.
  
LEDs (Low, Medium, High):
Indicate different water levels visually:
  Low Level: Illuminates the first LED.
  Medium Level: Illuminates the second LED.
  High Level: Illuminates the third LED.
  
## 3. Implementation
Electrodes and Capacitor Configuration:
Two metal plates act as electrodes, placed parallel to each other inside the container.
A 10 nF capacitor is connected in parallel with the electrodes.

### Connections:
One electrode is connected to a digital pin (pin 2) on the Arduino.
The other electrode is connected to the ground.
The capacitor is also connected between pin 2 and the ground.
### LED Indicators:
Three LEDs are connected to pins 3, 4, and 5 of the Arduino, each with a 220Ω resistor in series to limit current.
Software Implementation
The Arduino program measures the charging time of the capacitor to determine the water level:
### Capacitor Discharge:
The capacitor is first discharged by setting pin 2 to LOW.
### Charging Time Measurement:
The time taken for the capacitor to charge to a threshold voltage is measured using the micros() function.
Water Level Detection:
The measured charging time is compared with predefined thresholds:

Low Level: Charge time < 10800 microseconds.
![photo_6044130428975170459_y](https://github.com/user-attachments/assets/334605bb-764f-4284-a0c3-f08bc77522ae)
![photo_6044130428975170455_y](https://github.com/user-attachments/assets/2277c2d2-a853-4ec8-ab91-2c826225ea26)

Medium Level: Charge time between 10900 and 11250 microseconds.

High Level: Charge time > 11250 microseconds.
![photo_6044130428975170457_y](https://github.com/user-attachments/assets/1f332bc8-b1bf-443b-a6ea-2ab18ae0c87f)
![photo_6044130428975170456_y](https://github.com/user-attachments/assets/c3240463-0cef-4adf-ab18-db10be10adc7)


### LED Control:
The corresponding LED is lit based on the detected water level.
## 4. Results
The capacitive water level sensor successfully measured water levels in a container, providing visual feedback via LEDs. The results were as follows:

Low Water Level: The first LED illuminated when the charge time was less than 10800 microseconds.
Medium Water Level: The second LED illuminated when the charge time was between 10900 and 11250 microseconds.
High Water Level: The third LED illuminated when the charge time exceeded 11250 microseconds.
The sensor performed reliably, with consistent results across multiple tests. The inclusion of 220Ω resistors protected the LEDs while ensuring optimal brightness.

## Conclusion
This project demonstrated the feasibility of a capacitive water level sensor using simple and affordable components. The Arduino-based solution is accurate and can be customized for various applications. Future enhancements could include interfacing the system with an LCD display for more detailed output or incorporating wireless communication for remote monitoring.

