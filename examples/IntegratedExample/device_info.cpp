#include "device_info.h"

void setupDeviceInformation(NimBLEServer* server) {
  // Create Device Information Service
  BTDevInf devInfo(server);
  
  // Set basic device information
  devInfo.setModelNumberString("MODEL-1");
  devInfo.setSerialNumberString("SN0123456789");
  devInfo.setFirmwareRevisionString("1.0.0");
  devInfo.setHardwareRevisionString("Rev A");
  devInfo.setManufacturerNameString("My Company");
  
  // Start the service
  devInfo.startService();
} 