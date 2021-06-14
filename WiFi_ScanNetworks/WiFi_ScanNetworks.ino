/*
   Sketch for testing the WiFi on a Wemos D1 Mini or Wemos D1 Mini Pro
*/

#include "ESP8266WiFi.h"

char netid[33];           // Can hold an SSID up to 32 chharacters
char prBuffer[48];        // Print buffer


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("WiFi_ScanNetworks.ino"));

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);


}

void loop()
{
  Serial.println("\nScan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" network(s) found");

  for (int i = 0; i < n; i++) {
    strcpy(netid, WiFi.SSID(i).c_str());
    sprintf(prBuffer, "%15.10s %3d", netid, WiFi.RSSI(i));
    Serial.println(prBuffer);
    //Serial.print(netid);
    //Serial.print(F("     "));
    //Serial.println(WiFi.RSSI(i));
  }

  delay(5000);
}
