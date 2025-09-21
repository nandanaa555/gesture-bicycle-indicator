#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

RH_ASK driver;
MPU6050 mpu;

// Accelerometer and Gyroscope readings
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
    Serial.begin(9600); // Debugging only

    // Initialize RF driver
    if (!driver.init()) {
        Serial.println("RF init failed");
    }

    // Initialize MPU6050
    Wire.begin();
    mpu.initialize();

    // Check MPU6050 connection
    if (mpu.testConnection()) {
        Serial.println("MPU6050 connected!");
    } else {
        Serial.println("MPU6050 connection failed!");
    }
}

void loop() {
    // Predefined gesture messages
    const char *msgDown = "1";
    const char *msgLeft = "2";
    const char *msgRight = "3";
    const char *msgFront = "4";

    // Read accelerometer data
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Map accelerometer values to a range (0 to 255)
    int mappedX = map(ax, -17000, 17000, 0, 255); // X-axis data
    int mappedY = map(ay, -17000, 17000, 0, 255); // Y-axis data

    // Print raw and mapped data for debugging
    Serial.print("Raw X: ");
    Serial.print(ax);
    Serial.print(" | Mapped X: ");
    Serial.print(mappedX);
    Serial.print(" | Raw Y: ");
    Serial.print(ay);
    Serial.print(" | Mapped Y: ");
    Serial.println(mappedY);

    // Gesture recognition based on mapped values
    if (mappedY < 80) { // Gesture: Down
        Serial.println("Gesture: Down");
        driver.send((uint8_t *)msgDown, strlen(msgDown));
         
    } else if (mappedX > 200) { // Gesture: Left
        Serial.println("Gesture: Left");
        driver.send((uint8_t *)msgLeft, strlen(msgLeft));
    } else if (mappedX < 50) { // Gesture: Right
        Serial.println("Gesture: Right");
        driver.send((uint8_t *)msgRight, strlen(msgRight));
    } else if (mappedY > 180) { // Gesture: Front (moving upwards)
        Serial.println("Gesture: Front");
        driver.send((uint8_t *)msgFront, strlen(msgFront));
    }

    // Wait until the packet is sent
    driver.waitPacketSent();

    // Small delay for stability
    delay(100);
}