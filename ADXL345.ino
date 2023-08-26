#include <Wire.h>

#define ADXL345_ADDRESS 0x53
#define SDA_PIN A4
#define SCL_PIN A5

void setup() {
  Wire.begin();
  Serial.begin(9600);
  // Set ADXL345 measurement mode
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(0x2D); // Power control register
  Wire.write(8);    // Enable measurement mode (Bit 3 HIGH)
  Wire.endTransmission();
}

void loop() {
  int16_t x, y, z;
  
  // Read accelerometer data
  Wire.beginTransmission(ADXL345_ADDRESS);
  Wire.write(0x32); // Start reading from register 0x32 (X0)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345_ADDRESS, 6, true); // Request 6 bytes (2 bytes for each axis)
  
  // Read the 3-axis data
  x = Wire.read() | (Wire.read() << 8);
  y = Wire.read() | (Wire.read() << 8);
  z = Wire.read() | (Wire.read() << 8);
  
  // Display the X, Y, and Z axis readings
  Serial.print("X: "); Serial.print(x); Serial.print("\t");
  Serial.print("Y: "); Serial.print(y); Serial.print("\t");
  Serial.print("Z: "); Serial.print(z); Serial.println();
  
  delay(500); // Adjust this delay as needed for the desired data update rate
}
