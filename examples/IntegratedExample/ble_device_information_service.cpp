#include "ble_device_information_service.h"

void bleStartDeviceInformationService() {
  BTDevInf device_info = BTDevInf(NimBLEDevice::getServer());
  
  // Set basic device information
  device_info.setModelNumberString("MODEL-1");
  device_info.setSerialNumberString("SN0123456789");
  device_info.setFirmwareRevisionString("1.0.0");
  device_info.setHardwareRevisionString("Rev A");
  device_info.setManufacturerNameString("My Company");
  
  device_info.startService();
} 