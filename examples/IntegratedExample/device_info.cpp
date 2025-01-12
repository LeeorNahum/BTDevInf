#include "device_info.h"

void setupDeviceInformation(NimBLEServer* server) {
  // Create Device Information Service
  BTDevInf devInfo(server);
  
  // Set basic device information
  devInfo.setManufacturerNameString("My Company");
  devInfo.setModelNumberString("MODEL-1");
  devInfo.setFirmwareRevisionString("1.0.0");
  devInfo.setHardwareRevisionString("Rev A");
  devInfo.setSerialNumberString("SN0123456789");
  
  // Optional: Set additional information
  devInfo.setCountryCode(840); // USA
  devInfo.setDateOfManufacture(DateUTC(2025, 1, 12));
  
  // Start the service
  devInfo.startService();
} 