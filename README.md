# WEATHER_STATION_USING_BLYNK-IOT 🌦️🛑

> **IoT-based Real-Time Weather and Air Quality Station Using ESP32, DHT22, and Blynk**

![System Overview](images/system_overview.png)

This project implements a smart weather and gas monitoring system using the ESP32 microcontroller. It measures temperature, humidity, gas levels, and rainfall, and visualizes the data in real-time using the **Blynk IoT platform**. Ideal for environmental monitoring applications.

---

## 🔧 Features

- 🌡️ Measures **temperature** and **humidity** using a DHT22 sensor
- 💨 Monitors **gas levels** with an analog gas sensor
- 🌧️ Detects **rain** via analog and digital rain sensors
- 📡 Sends data to the **Blynk cloud dashboard** in real-time
- 🌐 Connects over Wi-Fi for remote monitoring

---

## 🧰 Hardware Requirements

| Component         | Description                         | Image |
|------------------|-------------------------------------|-------|
| ESP32            | Wi-Fi-enabled microcontroller        | ![](images/ESP32-Pinout.webp) |
| DHT22            | Temperature & Humidity sensor        | ![](images/mpu6050.jpeg) |
| MQ Gas Sensor    | Analog gas detection                 | ![](images/BO%20motor.jpeg) |
| Rain Sensor      | Analog and digital output supported  | ![](images/Breadboard%20power%20supply%20module.jpg) |
| Battery (e.g., 2200mAh) | Power source                 | ![](images/2200mah.jpeg) |

---

## 🗂️ File Overview

| File Name            | Description                      |
|---------------------|----------------------------------|
| `sketch_nov28a.ino` | Main Arduino code for ESP32 setup and sensor readings |
| `README.md`         | Project documentation (this file) |

---

## 🚀 Setup Instructions

### 1. Configure Blynk

- Create a new template on [Blynk IoT](https://blynk.cloud/)
- Note your **Template ID**, **Template Name**, and **Auth Token**
- Create virtual datastreams:
  - `V0` → Temperature
  - `V1` → Humidity
  - `V2` → Gas level
  - `V3` → Rain value

### 2. Flash the Code

1. Open `sketch_nov28a.ino` in Arduino IDE.
2. Install required libraries:
   - `Blynk` (v2.0+)
   - `DHT sensor library`
3. Enter your:
   - Wi-Fi SSID and password
   - Blynk `auth[]`, `template ID`, and `template name`
4. Connect your ESP32 board and upload the sketch.

---

## 🖥️ Real-Time Monitoring Interface

![Blynk Dashboard](images/Blynk_Dashboard.png)

> _Live sensor readings shown using Blynk widgets: temperature, humidity, gas level, and rain status._

---

## 📌 Future Improvements

- [ ] Add more air quality sensors (CO2, PM2.5)
- [ ] Integrate local OLED display for offline mode
- [ ] Log sensor data to SD card or cloud database
- [ ] Trigger alerts on abnormal gas or weather conditions

---

## 👨‍💻 Author

**[DEEPAK KUMAR VISHWAKARMA]**  
IoT & Embedded Systems Developer  
|Electronics & Telecommunication Engineer|
[LinkedIn](https://www.linkedin.com/in/deepakkumarvishwakarma/)

-
