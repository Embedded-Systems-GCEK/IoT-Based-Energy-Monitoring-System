#include "acs712.h"
#define ACS712_PIN A0     // ACS712 OUT pin connected to A0

// Global Variables
int rawADC = 0;                 // Raw ADC value
float sensorVoltage = 0.0;      // Voltage from ACS712
float currentValue = 0.0;       // Calculated current
float powerValue = 0.0;         // Power in watts
float energyValue = 0.0;        // Energy in watt-hour (Wh)

// ACS712 Parameters
static float adcReference = 3.3;       // ESP8266 ADC reference voltage
static float zeroCurrentVoltage = 2.5; // ACS712 zero-current output
static float sensitivity = 0.185;      // For ACS712-5A (V/A)

// Electrical Parameters
static  float supplyVoltage = 230.0;    // AC mains voltage
float timeInterval = 1.0;       // Time interval in seconds


// -------------------- Function Definitions --------------------

/* Initialize ACS712 sensor pin
 */
void initCurrentSensor()
{
    pinMode(ACS712_PIN, INPUT);
}

/* Purpose : Read analog value from ACS712
 */
int readCurrentSensor()
{
    return analogRead(ACS712_PIN);
}

/* Purpose : Convert ADC value to actual current
 */
float convertToCurrent(int adcValue)
{
    float voltage;
    float current;

    // Convert ADC value to voltage
    voltage = (adcValue * adcReference) / 1023.0;

    // Calculate current using ACS712 formula
    current = (voltage - zeroCurrentVoltage) / sensitivity;

    // Absolute value to avoid negative current
    if (current < 0)
        current = -current;

    return current;
}

/* Purpose : Calculate power and accumulated energy
 */
void calculatePowerAndEnergy(float current)
{
    // Power calculation
    powerValue = supplyVoltage * current;

    // Energy calculation (Wh)
    energyValue = energyValue + (powerValue * timeInterval / 3600.0);
}