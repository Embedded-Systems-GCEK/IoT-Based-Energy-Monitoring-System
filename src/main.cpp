/*
  Author: Anamika VV
  Date: 12-12-2025
*/
#include <Arduino.h>
#include <acs712.h>

/*
1.Initialize serial monitor
2.Initialize ESP8266 ? i dont know
3.Display current on serial monitor
4.Show the result
5.Go to step 4
*/


//Pin Definition


void setup()
{
    // Initialize Serial Monitor
    Serial.begin(9600);
    Serial.println("ESP8266 ACS712 Energy Monitoring System");
    Serial.println("--------------------------------------");

    // ESP8266 initialization
    // Initialize ACS712 sensor
    initCurrentSensor();
}

// Loop Function
void loop()
{
    // Step 1: Read raw ADC value from ACS712
    int rawADC = readCurrentSensor();

    // Step 2: Convert ADC reading to current
    currentValue = convertToCurrent(rawADC);

    // Step 3: Calculate power and energy
    calculatePowerAndEnergy(currentValue);

    // Step 4: Display results on Serial Monitor
    Serial.print("ADC Value: ");
    Serial.println(rawADC);

    Serial.print("Current (A): ");
    Serial.println(currentValue, 3);

    Serial.print("Power (W): ");
    Serial.println(powerValue, 2);

    Serial.print("Energy (Wh): ");
    Serial.println(energyValue, 4);

    Serial.println("--------------------------------------");

    delay(1000);  // 1 second delay
}
