#include <BTDevInf.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("BTDevInf All Device Information Example");
  
  // Initialize BLE
  NimBLEDevice::init("BTDevInf Example");
  
  // Create Device Information Service
  BTDevInf devInfo(NimBLEDevice::createServer());
  
  // Set System ID (requires authentication to read)
  uint8_t system_id[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
  devInfo.setSystemID(system_id, sizeof(system_id));
  
  // Set various device information strings
  devInfo.setModelNumberString("EX-1000");
  devInfo.setSerialNumberString("SN123456789");  // Requires authentication to read
  devInfo.setFirmwareRevisionString("1.0.0");
  devInfo.setHardwareRevisionString("Rev A");
  devInfo.setSoftwareRevisionString("1.0.0");
  devInfo.setManufacturerNameString("Example Corp");
  
  // Set IEEE Regulatory Certification Data
  uint8_t ieee_data[] = {0x01, 0x02, 0x03, 0x04};  // Example data
  devInfo.setIEEERegulatoryCertificationDataList(ieee_data, sizeof(ieee_data));
  
  // Set PnP ID
  // vendor_id_source: 0x01 for Bluetooth SIG, 0x02 for USB Implementer's Forum
  // vendor_id: Company identifier
  // product_id: Vendor-assigned product ID
  // product_version: JJ.M.N format (0x0100 for 1.0.0)
  devInfo.setPnPID(0x02, 0x303A, 0x1001, 0x0100);
  
  // Set UDI for Medical Devices (requires authentication to read)
  // Unique Device Identifier as assigned to medical devices
  const char* udi = "(01)12345678901234";
  devInfo.setUDIForMedicalDevices((const uint8_t*)udi, strlen(udi));
  
  // Start the service
  devInfo.startService();
  
  // Start advertising
  NimBLEDevice::getAdvertising()->start();
  
  Serial.println("Device Information Service started");
  Serial.println("Advertising started");
  Serial.println("\nCharacteristics that require authentication to read:");
  Serial.println("- System ID");
  Serial.println("- Serial Number");
  Serial.println("- UDI for Medical Devices");
}

void loop() {
  delay(2000);
} 