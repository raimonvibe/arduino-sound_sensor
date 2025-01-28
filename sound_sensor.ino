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

