
---

## 🚀 Quick Start
1. **Upload Transmitter Code**  
   - Open `Transmitter/transmitter.ino` in Arduino IDE  
   - Upload to Arduino Nano connected to MPU6050 + RF Tx

2. **Upload Receiver Code**  
   - Open `Receiver/receiver.ino` in Arduino IDE  
   - Upload to Arduino Nano connected to RF Rx + LEDs

3. **Gesture Controls**  
   - **Left (tilt left)** → Left LED ON  
   - **Right (tilt right)** → Right LED ON  
   - **Front (move hand upward)** → Front LED ON

---

## 📷 Wiring Diagram
- Tx: MPU6050 SDA→A4, SCL→A5, VCC→5V, GND→GND; RF Tx DATA→D12, VCC→5V, GND→GND  
- Rx: RF Rx DATA→D11, VCC→5V, GND→GND; LEDs on D3/D4/D5 (with resistors), common GND  
- Attach ~17.3 cm antenna wire to both Tx & Rx  

*(See `media/wiring-diagram.png` for visual reference)*

---

## 🔋 Tips for Best Results
- Use a 17.3 cm antenna on both Tx & Rx for reliable range  
- Ensure a common ground between all modules & Arduinos  
- If Rx is noisy, add a 100µF capacitor across VCC-GND of the receiver module  
- Calibrate gesture thresholds if needed for your mounting orientation

---

## 📜 License
This project is licensed under the [MIT License](LICENSE)

---

## 👩‍💻 Author
- **Nandanaa M S** — Robotics & Automation Enthusiast
