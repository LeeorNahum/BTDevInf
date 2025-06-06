#include "BTDevInf.h"

/**
 * @brief Construct a BTDevInf instance
 * @param server A pointer to the server instance this Device Information Service will use
 * @note This service exposes manufacturer and/or vendor information about a device.
 */
BTDevInf::BTDevInf(NimBLEServer* server) {
  if (server == nullptr) return;
  
  device_info_service = nullptr;
  
  system_id_characteristic = nullptr;
  model_number_string_characteristic = nullptr;
  serial_number_string_characteristic = nullptr;
  firmware_revision_string_characteristic = nullptr;
  hardware_revision_string_characteristic = nullptr;
  software_revision_string_characteristic = nullptr;
  manufacturer_name_string_characteristic = nullptr;
  ieee_regulatory_certification_data_list_characteristic = nullptr;
  pnp_id_characteristic = nullptr;
  udi_for_medical_devices_characteristic = nullptr;
  
  // Get existing service or create new one
  device_info_service = server->getServiceByUUID(DEVICE_INFORMATION_SERVICE_UUID);
  if (device_info_service == nullptr) {
    device_info_service = server->createService(DEVICE_INFORMATION_SERVICE_UUID);
  }
}

/**
 * @brief Start the Device Information service
 * @return true if the service was started successfully, false otherwise
 */
bool BTDevInf::startService() {
  if (device_info_service) {
    return device_info_service->start();
  }
  return false;
}

void BTDevInf::setupDescriptors(NimBLECharacteristic* characteristic, const char* user_description, uint8_t format, int8_t exponent, uint16_t unit, uint8_t namespace_value, uint16_t description) {
  if (characteristic == nullptr) return;
  
  // User Description Descriptor
  NimBLEDescriptor* characteristic_user_description_descriptor = characteristic->createDescriptor(NimBLEUUID("2901"), NIMBLE_PROPERTY::READ);
  characteristic_user_description_descriptor->setValue(user_description);
  
  // Presentation Format Descriptor
  NimBLE2904* characteristic_presentation_format_descriptor = (NimBLE2904*)characteristic->createDescriptor(NimBLEUUID("2904"));
  
  characteristic_presentation_format_descriptor->setFormat(format);
  characteristic_presentation_format_descriptor->setExponent(exponent);
  characteristic_presentation_format_descriptor->setUnit(unit);
  characteristic_presentation_format_descriptor->setNamespace(namespace_value);
  characteristic_presentation_format_descriptor->setDescription(description);
}

void BTDevInf::createSystemIDCharacteristic() {
  if (device_info_service == nullptr || system_id_characteristic != nullptr) return;
  
  system_id_characteristic = device_info_service->getCharacteristic(SYSTEM_ID_CHARACTERISTIC_UUID);
  if (system_id_characteristic == nullptr) {
    system_id_characteristic = device_info_service->createCharacteristic(
      SYSTEM_ID_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::READ_AUTHEN
    );
    setupDescriptors(system_id_characteristic, "System ID", NimBLE2904::FORMAT_OPAQUE, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createModelNumberStringCharacteristic() {
  if (device_info_service == nullptr || model_number_string_characteristic != nullptr) return;
  
  model_number_string_characteristic = device_info_service->getCharacteristic(MODEL_NUMBER_STRING_CHARACTERISTIC_UUID);
  if (model_number_string_characteristic == nullptr) {
    model_number_string_characteristic = device_info_service->createCharacteristic(
      MODEL_NUMBER_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(model_number_string_characteristic, "Model Number", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createSerialNumberStringCharacteristic() {
  if (device_info_service == nullptr || serial_number_string_characteristic != nullptr) return;
  
  serial_number_string_characteristic = device_info_service->getCharacteristic(SERIAL_NUMBER_STRING_CHARACTERISTIC_UUID);
  if (serial_number_string_characteristic == nullptr) {
    serial_number_string_characteristic = device_info_service->createCharacteristic(
      SERIAL_NUMBER_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::READ_AUTHEN
    );
    setupDescriptors(serial_number_string_characteristic, "Serial Number", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createFirmwareRevisionStringCharacteristic() {
  if (device_info_service == nullptr || firmware_revision_string_characteristic != nullptr) return;
  
  firmware_revision_string_characteristic = device_info_service->getCharacteristic(FIRMWARE_REVISION_STRING_CHARACTERISTIC_UUID);
  if (firmware_revision_string_characteristic == nullptr) {
    firmware_revision_string_characteristic = device_info_service->createCharacteristic(
      FIRMWARE_REVISION_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(firmware_revision_string_characteristic, "Firmware Revision", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createHardwareRevisionStringCharacteristic() {
  if (device_info_service == nullptr || hardware_revision_string_characteristic != nullptr) return;
  
  hardware_revision_string_characteristic = device_info_service->getCharacteristic(HARDWARE_REVISION_STRING_CHARACTERISTIC_UUID);
  if (hardware_revision_string_characteristic == nullptr) {
    hardware_revision_string_characteristic = device_info_service->createCharacteristic(
      HARDWARE_REVISION_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(hardware_revision_string_characteristic, "Hardware Revision", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createSoftwareRevisionStringCharacteristic() {
  if (device_info_service == nullptr || software_revision_string_characteristic != nullptr) return;
  
  software_revision_string_characteristic = device_info_service->getCharacteristic(SOFTWARE_REVISION_STRING_CHARACTERISTIC_UUID);
  if (software_revision_string_characteristic == nullptr) {
    software_revision_string_characteristic = device_info_service->createCharacteristic(
      SOFTWARE_REVISION_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(software_revision_string_characteristic, "Software Revision", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createManufacturerNameStringCharacteristic() {
  if (device_info_service == nullptr || manufacturer_name_string_characteristic != nullptr) return;
  
  manufacturer_name_string_characteristic = device_info_service->getCharacteristic(MANUFACTURER_NAME_STRING_CHARACTERISTIC_UUID);
  if (manufacturer_name_string_characteristic == nullptr) {
    manufacturer_name_string_characteristic = device_info_service->createCharacteristic(
      MANUFACTURER_NAME_STRING_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(manufacturer_name_string_characteristic, "Manufacturer Name", NimBLE2904::FORMAT_UTF8, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createIEEERegulatoryCertificationDataListCharacteristic() {
  if (device_info_service == nullptr || ieee_regulatory_certification_data_list_characteristic != nullptr) return;
  
  ieee_regulatory_certification_data_list_characteristic = device_info_service->getCharacteristic(IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_CHARACTERISTIC_UUID);
  if (ieee_regulatory_certification_data_list_characteristic == nullptr) {
    ieee_regulatory_certification_data_list_characteristic = device_info_service->createCharacteristic(
      IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(ieee_regulatory_certification_data_list_characteristic, "IEEE Regulatory Certification", NimBLE2904::FORMAT_IEEE20601, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createPnPIDCharacteristic() {
  if (device_info_service == nullptr || pnp_id_characteristic != nullptr) return;
  
  pnp_id_characteristic = device_info_service->getCharacteristic(PNP_ID_CHARACTERISTIC_UUID);
  if (pnp_id_characteristic == nullptr) {
    pnp_id_characteristic = device_info_service->createCharacteristic(
      PNP_ID_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ
    );
    setupDescriptors(pnp_id_characteristic, "PnP ID", NimBLE2904::FORMAT_OPAQUE, 0x00, 0x0000, 0x01, 0x0000);
  }
}

void BTDevInf::createUDIForMedicalDevicesCharacteristic() {
  if (device_info_service == nullptr || udi_for_medical_devices_characteristic != nullptr) return;
  
  udi_for_medical_devices_characteristic = device_info_service->getCharacteristic(UDI_FOR_MEDICAL_DEVICES_CHARACTERISTIC_UUID);
  if (udi_for_medical_devices_characteristic == nullptr) {
    udi_for_medical_devices_characteristic = device_info_service->createCharacteristic(
      UDI_FOR_MEDICAL_DEVICES_CHARACTERISTIC_UUID,
      NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::READ_AUTHEN
    );
    setupDescriptors(udi_for_medical_devices_characteristic, "UDI for Medical Devices", NimBLE2904::FORMAT_OPAQUE, 0x00, 0x0000, 0x01, 0x0000);
  }
}

/**
 * @brief Set system ID
 * @param system_id A structure containing an Organizationally Unique Identifier (OUI) followed by a manufacturer-defined identifier
 * @param length Length of the data in octets
 * @return true if successful, false if service doesn't exist
 * @note This characteristic is used to represent an extended unique identifier (EUI) of the system implementing the service that contains this characteristic.
 * @note For more information about the System ID characteristic, see https://btprodspecificationrefs.blob.core.windows.net/gatt-specification-supplement/GATT_Specification_Supplement.pdf#page=168&zoom=100,96,296
 */
bool BTDevInf::setSystemID(const uint8_t* system_id, size_t length) {
  if (device_info_service == nullptr) return false;
  
  createSystemIDCharacteristic();
  
  system_id_characteristic->setValue(system_id, length);
  
  return true;
}

/**
 * @brief Set model number string
 * @param model_number_string The model number assigned by the device vendor
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents the model number that is assigned by the device vendor.
 */
bool BTDevInf::setModelNumberString(const std::string& model_number_string) {
  if (device_info_service == nullptr) return false;
  
  createModelNumberStringCharacteristic();
  
  model_number_string_characteristic->setValue(model_number_string);
  
  return true;
}

/**
 * @brief Set serial number string
 * @param serial_number_string The serial number of the device
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents the serial number for a particular instance of the device.
 */
bool BTDevInf::setSerialNumberString(const std::string& serial_number_string) {
  if (device_info_service == nullptr) return false;
  
  createSerialNumberStringCharacteristic();
  
  serial_number_string_characteristic->setValue(serial_number_string);
  
  return true;
}

/**
 * @brief Set firmware revision string
 * @param firmware_revision_string The firmware revision of the device
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents a revision identifier for the firmware within the device.
 */
bool BTDevInf::setFirmwareRevisionString(const std::string& firmware_revision_string) {
  if (device_info_service == nullptr) return false;
  
  createFirmwareRevisionStringCharacteristic();
  
  firmware_revision_string_characteristic->setValue(firmware_revision_string);
  
  return true;
}

/**
 * @brief Set hardware revision string
 * @param hardware_revision_string The hardware revision of the device
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents the hardware revision for the hardware within the device.
 */
bool BTDevInf::setHardwareRevisionString(const std::string& hardware_revision_string) {
  if (device_info_service == nullptr) return false;
  
  createHardwareRevisionStringCharacteristic();
  
  hardware_revision_string_characteristic->setValue(hardware_revision_string);
  
  return true;
}

/**
 * @brief Set software revision string
 * @param software_revision_string The software revision of the device
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents the software revision for the software within the device.
 */
bool BTDevInf::setSoftwareRevisionString(const std::string& software_revision_string) {
  if (device_info_service == nullptr) return false;
  
  createSoftwareRevisionStringCharacteristic();
  
  software_revision_string_characteristic->setValue(software_revision_string);
  
  return true;
}

/**
 * @brief Set manufacturer name string
 * @param manufacturer_name_string The name of the manufacturer of the device
 * @return true if successful, false if service doesn't exist
 * @note This characteristic represents the name of the manufacturer of the device. This value is set by the manufacturer or supplier of the device.
 */
bool BTDevInf::setManufacturerNameString(const std::string& manufacturer_name_string) {
  if (device_info_service == nullptr) return false;
  
  createManufacturerNameStringCharacteristic();
  
  manufacturer_name_string_characteristic->setValue(manufacturer_name_string);
  
  return true;
}

/**
 * @brief Set IEEE 11073-20601 regulatory certification data list
 * @param data The regulatory and certification information for the product in IEEE 11073-20601 format
 * @param length Length of the data in octets
 * @return true if successful, false if service doesn't exist
 * @note The content of this characteristic is determined by the authorizing organization that provides certifications
 * @note Refer to IEEE 11073-20601-2019 or later, or Continua Design Guidelines for more information on the format of this list
 * @note IEEE Health informatics--Personal health device communication - Part 20601: Application profile--Optimized Exchange Protocol; https://standards.ieee.org/ieee/11073-20601/6084/
 * @note Continua Design Guidelines - Personal Connected Health Alliance; https://www.pchalliance.org/continua-design-guidelines
 */
bool BTDevInf::setIEEERegulatoryCertificationDataList(const uint8_t* data, size_t length) {
  if (device_info_service == nullptr) return false;
  
  createIEEERegulatoryCertificationDataListCharacteristic();
  
  ieee_regulatory_certification_data_list_characteristic->setValue(data, length);
  
  return true;
}

/**
 * @brief Set PnP ID
 * @param vendor_id_source Vendor ID Source field
 * @param vendor_id Vendor ID field
 * @param product_id Product ID field
 * @param product_version Product Version field
 * @return true if successful, false if service doesn't exist
 * @note This characteristic is a set of values that is used to identify all devices of a given type/model/version.
 * @note ### Vendor ID Source field:
 * @note The Vendor ID Source field designates which organization assigned the value used in the Vendor ID field value.
 * @note - 0x01: Assigned Company Identifier value from the Bluetooth SIG Assigned Numbers https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Assigned_Numbers/out/en/Assigned_Numbers.pdf#page=213&zoom=100,96,77
 * @note - 0x02: USB Implementer's Forum assigned Vendor ID value
 * @note - 0x00, 0x03 to 0xFF: Reserved for future use
 * @note ### Vendor ID field
 * @note The Vendor ID field is intended to uniquely identify the vendor of the device. This field is used in conjunction with Vendor ID Source field, which determines which organization assigned the Vendor ID field value.
 * @note Note: The Bluetooth Special Interest Group assigns Device ID Vendor ID, and the USB Implementer's Forum assigns Vendor IDs, either of which can be used for the Vendor ID field value. Device providers should procure the Vendor ID from the USB Implementer's Forum or the Company Identifier from the Bluetooth SIG.
 * @note ### Product ID field
 * @note The Product ID field is intended to distinguish between different products made by the vendor identified with the Vendor ID field.
 * @note The vendors themselves manage Product ID field values.
 * @note ### Product Version field
 * @note The Product Version field is a numeric expression identifying the device release number in Binary-Coded Decimal. This is a vendor-assigned value that defines the version of the product identified by the Vendor ID and Product ID fields. This field is intended to differentiate between versions of products with identical Vendor IDs and Product IDs. The value of the field value is 0xJJMN for version JJ.M.N (JJ – major version number, M – minor version number, N – sub-minor version number); e.g., version 2.1.3 is represented with a value of 0x0213 and version 2.0.0 is represented with a value of 0x0200. When upward-compatible changes are made to the device, it is recommended that the minor version number be incremented. If incompatible changes are made to the device, it is recommended that the major version number be incremented. The sub-minor version is incremented for bug fixes.
 * @note The vendors themselves manage Product Version field values.
 */
bool BTDevInf::setPnPID(uint8_t vendor_id_source, uint16_t vendor_id, uint16_t product_id, uint16_t product_version) {
  if (device_info_service == nullptr) return false;
  
  createPnPIDCharacteristic();
  
  uint8_t pnp[] = {
    vendor_id_source,
    static_cast<uint8_t>(vendor_id & 0xFF),
    static_cast<uint8_t>((vendor_id >> 8) & 0xFF),
    static_cast<uint8_t>(product_id & 0xFF),
    static_cast<uint8_t>((product_id >> 8) & 0xFF),
    static_cast<uint8_t>(product_version & 0xFF),
    static_cast<uint8_t>((product_version >> 8) & 0xFF)
  };
  pnp_id_characteristic->setValue(pnp, sizeof(pnp));
  
  return true;
}

/**
 * @brief Set UDI for Medical Devices
 * @param udi The Unique Device Identifier (UDI) as assigned to the medical device
 * @param length Length of the data in octets
 * @return true if successful, false if service doesn't exist
 * @note The UDI for Medical Devices characteristic is a structure that contains the Unique Device Identifier (UDI) as assigned to the medical device. When the device has a label representing the UDI, the UDI for Medical Devices characteristic shall represent the same value.
 * @note The UDI of a personal medical device is seen as Protected Health Information.
 */
bool BTDevInf::setUDIForMedicalDevices(const uint8_t* udi, size_t length) {
  if (device_info_service == nullptr) return false;
  
  createUDIForMedicalDevicesCharacteristic();
  
  udi_for_medical_devices_characteristic->setValue(udi, length);
  
  return true;
}