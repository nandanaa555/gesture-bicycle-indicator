#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

// Define LED pins
#define LED1 3  // For gesture 1
#define LED2 4  // For gesture 2
#define LED3 5  // For gesture 3
#define LED4 6  // For gesture 4

void setup() {
    Serial.begin(9600); // For debugging
    if (!driver.init()) {
        Serial.println("init failed");
        while (1); // Stop execution if initialization fails
    }

    // Initialize LED pins as output
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    // Ensure LEDs are off initially
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}

void loop() {
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);

    // Check if a message was received
    if (driver.recv(buf, &buflen)) {
        buf[buflen] = '\0'; // Null-terminate the message for easier printing
        Serial.print("Received message: ");
        Serial.println((char*)buf);

        // Interpret the received gesture
        if (strcmp((char*)buf, "1") == 0) {
            // Gesture 1: Turn on LED1
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, LOW);
            digitalWrite(LED4, LOW);
        } else if (strcmp((char*)buf, "2") == 0) {
            // Gesture 2: Turn on LED2
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, LOW);
            digitalWrite(LED4, LOW);
        } else if (strcmp((char*)buf, "3") == 0) {
            // Gesture 3: Turn on LED3
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, HIGH);
            digitalWrite(LED4, LOW);
        } else if (strcmp((char*)buf, "4") == 0) {
            // Gesture 4: Turn on LED4
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, LOW);
            digitalWrite(LED4, HIGH);
        } else {
            // If the message doesn't match known gestures, turn off all LEDs
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, LOW);
            digitalWrite(LED4, LOW);
        }
    }
}