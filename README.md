# Smart Attendance System using RFID and ESP32

This is a hardware-software integration project developed as part of the Digital Systems and Microprocessor course at SSN College of Engineering. It automates the attendance tracking process using RFID technology and an ESP32 microcontroller, logging attendance directly to Microsoft Excel via PLX-DAQ.

## About the Project

The Smart Attendance System is designed to improve the efficiency, accuracy, and reliability of traditional attendance systems. It uses RFID cards assigned to users, which are scanned by an RFID reader connected to an ESP32 microcontroller. Upon scanning, the system sends attendance data (Name, UID, Date, Time) directly into an Excel spreadsheet using serial communication through the PLX-DAQ tool.

The project offers a low-cost, scalable solution suitable for schools, colleges, and workplaces. It eliminates the need for manual logging, reduces the chances of proxy attendance, and ensures data is stored in a digital and easily accessible format.

## Technologies Used

- *Microcontroller:* ESP32
- *RFID Reader:* MFRC522
- *Programming Language:* C/C++ (Arduino IDE)
- *Data Logging Tool:* PLX-DAQ (for Excel integration)
- *Circuit Design:* Breadboard + jumper wires or PCB

## How to Run

1. Connect the ESP32 board and RFID reader (MFRC522) as per the circuit diagram.
2. Upload the Arduino C++ code to the ESP32 using the Arduino IDE.
3. Open *Excel* and start PLX-DAQ to receive serial data from ESP32.
4. Place an RFID card near the reader.
5. Attendance data will be logged into Excel in real-time (UID, Name, Date, Time).

> Note: Make sure the COM port in PLX-DAQ matches the one used by ESP32.

