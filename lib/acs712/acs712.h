// Author  : FathimathSafaKT
// Date    : 12-12-2025

/*
1.Initialize current sensor
2.Read values from the current sensor
3.Convert sensor reading to current
4.Calculate energy and power
*/
// Function Prototype
#ifndef acs712_H
#define acs712_H
#include <Arduino.h>

void initCurrentSensor();
int readCurrentSensor();
float convertToCurrent(int adcValue);
void calculatePowerAndEnergy(float current);

<<<<<<< HEAD
extern float currentValue;      // Calculated current
extern float powerValue;         // Power in watts
extern float energyValue;  
#endif
=======
extern float currentValue = 0.0; // Calculated current
extern float powerValue = 0.0;   // Power in watts
extern float energyValue = 0.0;
#endif
>>>>>>> 9852bd86e27dae887a8cad00ed752739096ae320
