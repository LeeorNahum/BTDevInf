#include <BTDevInf.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("BTDevInf Basic Example");
  
  // Initialize BLE
  NimBLEDevice::init("BTDevInf Example");
  
  // Create Device Information Service
  BTDevInf devInfo(NimBLEDevice::createServer());
  
  // Set various device information strings
  devInfo.setFirmwareRevisionString("1.0.0");
  devInfo.setHardwareRevisionString("Rev A");
  devInfo.setManufacturerNameString("Example Corp");
  devInfo.setModelNumberString("EX-1000");
  devInfo.setSerialNumberString("SN123456789");
  devInfo.setSoftwareRevisionString("1.0.0");
  
  // Set PnP ID
  // vendor_id_source: 0x01 for Bluetooth SIG, 0x02 for USB Implementer's Forum
  // vendor_id: Company identifier
  // product_id: Vendor-assigned product ID
  // product_version: JJ.M.N format (0x0100 for 1.0.0)
  devInfo.setPnPID(0x02, 0x303A, 0x1001, 0x0100);
  
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