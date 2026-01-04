#include "monitoring_server.h"


volatile float *voltage; // Example voltage value
volatile float *current;   // This will be updated from the main loop

void initMonitoringServer(int port ,float *_voltage,float *_current){
    current = _current;
    voltage = _voltage;
}
extern ESP8266WebServer server;
void handleReadings() {
  JsonDocument jsonDoc;

  jsonDoc["voltage"] = *voltage;
  jsonDoc["current"] = *current;

  String jsonResponse;
  serializeJson(jsonDoc, jsonResponse);
 
  server.send(200, "application/json", jsonResponse);
}