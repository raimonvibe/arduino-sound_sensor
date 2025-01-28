# 🔊 Sound Detection with KY-038 Sensor and Arduino

![Sound Sensor](sound_sensor.JPG)

## 📜 Overview
This project uses a **KY-038 Sound Sensor Module** with an **Arduino** to detect sudden sound changes and trigger an action (LED ON). It reads the **analog sound level**, compares it to a baseline noise level, and activates an LED if the noise exceeds a threshold.  

## 🛠️ Hardware Required
- 🟢 **KY-038 Sound Sensor Module**
- 🟦 **Arduino (Uno, Mega, Nano, etc.)**
- 🔴 **Jumper wires**
- 💡 **LED (optional, using built-in LED on pin 13)**

## 📡 Wiring Diagram
| KY-038 Pin | Arduino Pin |
|------------|------------|
| **VCC**    | 5V         |
| **GND**    | GND        |
| **A0**     | A0         |
| **D0** (optional) | D2 |

## 🔬 How It Works
1. The **sound sensor** measures ambient noise using the **A0 pin**.
2. The script calculates the **difference** between the current reading and a **baseline noise level**.
3. If the difference exceeds the **threshold**, the **LED turns on**.
4. The threshold and baseline levels can be **adjusted** based on environment conditions.

## 📜 Arduino Code
```cpp
const int soundSensor = A0;
const int ledPin = 13;
int baseNoiseLevel = 25;  // Adjust based on min/max findings
int threshold = 10;        // Sensitivity level

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int soundValue = analogRead(soundSensor);
    int difference = abs(soundValue - baseNoiseLevel);  // Difference from base level

    Serial.print("Sound Level: ");
    Serial.print(soundValue);
    Serial.print(" | Difference: ");
    Serial.println(difference);

    if (difference > threshold) {
        Serial.println("Loud Sound Detected!");
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }

    delay(100);
}
```

## 📊 Expected Serial Monitor Output
```
Sound Level: 26 | Difference: 1
Sound Level: 27 | Difference: 2
Sound Level: 80 | Difference: 55  <-- Loud sound detected!
Loud Sound Detected!
```

## 🎯 How to Calibrate
1. **Find the baseline noise level:**  
   - Run the script and observe the **minimum and maximum values** in a quiet environment.
   - Update `baseNoiseLevel` accordingly.
   
2. **Adjust the threshold:**  
   - Increase the **threshold value** if false detections occur.
   - Decrease it if the sensor **doesn’t detect loud sounds**.

## 🛠️ Troubleshooting
| Issue | Solution |
|-------|----------|
| No response from sensor | Check **wiring** and **power connections** |
| LED stays on constantly | **Increase threshold** value |
| LED never turns on | **Lower the threshold** or **adjust potentiometer** on the sensor |

## 🧪 Next Steps
- 📟 **Add an LCD display** to show real-time noise levels.
- 📊 **Use a buzzer** instead of an LED for an alarm system.
- 📈 **Implement FFT analysis** for sound frequency detection.

---

**🔬 Science + Code = Fun!** Happy experimenting! 😊

