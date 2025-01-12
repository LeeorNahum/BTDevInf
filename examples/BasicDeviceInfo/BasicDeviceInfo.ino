#include <BTDevInf.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("BTDevInf Basic Example");
  
  // Initialize BLE
  NimBLEDevice::init("BTDevInf Example");
  
  // Create Device Information Service
  BTDevInf devInfo(NimBLEDevice::createServer());
  
  // Set country code (840 = USA)
  devInfo.setCountryCode(840);
  
  // Set date of manufacture (UTC)
  devInfo.setDateOfManufacture(DateUTC(2024, 1, 9));
  
  // Set various device information strings
  devInfo.setFirmwareRevisionString("1.0.0");
  devInfo.setGlobalTradeItemNumber(123456789012);  // Up to 48-bit number
  devInfo.setHardwareRevisionString("Rev A");
  devInfo.setManufacturerNameString("Example Corp");
  devInfo.setModelNumberString("EX-1000");
  devInfo.setSerialNumberString("SN123456789");
  devInfo.setSoftwareRevisionString("1.0.0");
  
  // Start the service
  devInfo.startService();
  
  // Start advertising
  NimBLEDevice::getAdvertising()->start();
  
  Serial.println("Device Information Service started");
  Serial.println("Advertising started");
}

void loop() {
  delay(2000);
}