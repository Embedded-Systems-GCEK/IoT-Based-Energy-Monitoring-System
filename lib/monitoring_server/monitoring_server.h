#ifndef _MONITORING_SERVER_H
#define _MONITORING_SERVER_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>





void handleReadings();
void initMonitoringServer(int port , float* ,float*);


#endif _MONITORING_SERVER_H