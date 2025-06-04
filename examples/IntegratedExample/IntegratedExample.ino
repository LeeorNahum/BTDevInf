#include <NimBLEDevice.h>
#include "ble_device_information_service.h"

// Example BLE service and characteristic
const NimBLEUUID SERVICE_UUID        ("686f2d92-3977-41da-9670-90a68d37e560");
const NimBLEUUID CHARACTERISTIC_UUID ("13888317-ac6e-4a9f-8e49-988e4b629219");

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("BTDevInf Integration Example");
  
  // Initialize BLE
  NimBLEDevice::init("My BLE Device");
  
  // Create the server
  NimBLEServer *server = NimBLEDevice::createServer();
  
  // Create the main service for your application
  NimBLEService *mainService = server->createService(SERVICE_UUID);
  NimBLECharacteristic *characteristic = mainService->createCharacteristic(
    CHARACTERISTIC_UUID,
    NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE
  );
  characteristic->setValue("Hello World");
  mainService->start();
  
  // Setup device information service
  bleStartDeviceInformationService();
  
  // Start advertising
  NimBLEDevice::getAdvertising()->start();
  
  Serial.println("Main service and Device Information Service started");
  Serial.println("Advertising started");
}

void loop() {
  delay(2000);
} 