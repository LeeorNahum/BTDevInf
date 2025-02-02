# BTDevInf

BTDevInf is a library for ESP32 that implements the Bluetooth Device Information Service. It provides a simple interface to expose manufacturer and vendor information about your device over BLE, following the official Bluetooth specification. The library is based on the NimBLE-Arduino library.

## Installation

### Arduino IDE

1. Download the library as a ZIP file.
2. Open the Arduino IDE.
3. Go to `Sketch` > `Include Library` > `Add .ZIP Library`.
4. Select the downloaded ZIP file.

### PlatformIO

Add the following to your `platformio.ini`:

```ini
lib_deps =
  https://github.com/LeeorNahum/BTDevInf.git
```

## Usage

There are three ways to use this library, demonstrated in the examples:

### Basic Usage

The [BasicDeviceInfo](examples/BasicDeviceInfo/BasicDeviceInfo.ino) example shows the minimal setup needed to expose common device information:

```cpp
#include "BTDevInf.h"

void setup() {
    NimBLEDevice::init("My Device");
    
    BTDevInf devInfo(NimBLEDevice::createServer());
    
    devInfo.setManufacturerNameString("My Company");
    devInfo.setModelNumberString("MODEL-1");
    devInfo.setFirmwareRevisionString("1.0.0");
    
    devInfo.startService();
    NimBLEDevice::getAdvertising()->start();
}
```

### Complete Device Information

The [AllDeviceInfo](examples/AllDeviceInfo/AllDeviceInfo.ino) example demonstrates all available characteristics.

### Integration Example

The [IntegratedExample](examples/IntegratedExample/IntegratedExample.ino) shows how to incorporate device information into an existing BLE project by separating the configuration into dedicated files.

## Characteristics

The Device Information Service (UUID: 180A) contains the following characteristics:

| Characteristic | UUID | Properties | Description |
|---------------|------|------------|-------------|
| System ID | 2A23 | Read, Auth | Extended unique identifier (EUI) of the system |
| Model Number String | 2A24 | Read | Model number assigned by device vendor |
| Serial Number String | 2A25 | Read, Auth | Serial number for a particular device instance |
| Firmware Revision String | 2A26 | Read | Revision for the firmware within the device |
| Hardware Revision String | 2A27 | Read | Revision for the hardware within the device |
| Software Revision String | 2A28 | Read | Revision for the software within the device |
| Manufacturer Name String | 2A29 | Read | Name of the manufacturer of the device |
| IEEE Regulatory Certification | 2A2A | Read | IEEE 11073-20601 regulatory certification data list |
| PnP ID | 2A50 | Read | Vendor ID Source, Vendor ID, Product ID, and Product Version |
| UDI for Medical Devices | 2BFF | Read, Auth | Unique Device Identifier for medical devices |

## Security

Some characteristics contain personally identifiable information (PII) and require authentication to read:

- System ID
- Serial Number String
- UDI for Medical Devices

## Documentation

For more information about the Device Information Service, see:

- [Device Information Service Specification](https://www.bluetooth.com/specifications/specs/device-information-service/)
- [Device Properties Specification](https://btprodspecificationrefs.blob.core.windows.net/device-properties/Device_Properties.pdf)
