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

The [AllDeviceInfo](examples/AllDeviceInfo/AllDeviceInfo.ino) example demonstrates all available characteristics, including:

- System ID
- Model Number
- Serial Number
- Firmware Revision
- Hardware Revision
- Software Revision
- Manufacturer Name
- IEEE Regulatory Certification Data List
- PnP ID
- Country Code
- Date of Manufacture
- Global Trade Item Number
- UDI for Medical Devices

### Integration Example

The [IntegratedExample](examples/IntegratedExample/IntegratedExample.ino) shows how to incorporate device information into an existing BLE project by separating the configuration into dedicated files.

## Characteristics

The Device Information Service includes the following characteristics:

- System ID (0x2A23)
- Model Number String (0x2A24)
- Serial Number String (0x2A25)
- Firmware Revision String (0x2A26)
- Hardware Revision String (0x2A27)
- Software Revision String (0x2A28)
- Manufacturer Name String (0x2A29)
- IEEE 11073-20601 Regulatory Certification Data List (0x2A2A)
- PnP ID (0x2A50)
- Country Code (0x2AEC)
- Date of Manufacture (0x2AED)
- Global Trade Item Number (0x2AFA)
- UDI for Medical Devices (0x2BFF)

## Security

Some characteristics contain personally identifiable information (PII) and require authentication to read:

- System ID
- Serial Number
- UDI for Medical Devices

## Documentation

For more information about the Device Information Service, see:

- [Device Information Service Specification](https://www.bluetooth.com/specifications/specs/device-information-service/)

- [Device Properties Specification](https://btprodspecificationrefs.blob.core.windows.net/device-properties/Device_Properties.pdf)
