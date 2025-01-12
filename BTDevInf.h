#ifndef BTDEVINF_H
#define BTDEVINF_H

#include <NimBLEDevice.h>

const NimBLEUUID DEVICE_INFORMATION_SERVICE_UUID("180A");

const NimBLEUUID SYSTEM_ID_CHARACTERISTIC_UUID("2A23");
const NimBLEUUID MODEL_NUMBER_STRING_CHARACTERISTIC_UUID("2A24");
const NimBLEUUID SERIAL_NUMBER_STRING_CHARACTERISTIC_UUID("2A25");
const NimBLEUUID FIRMWARE_REVISION_STRING_CHARACTERISTIC_UUID("2A26");
const NimBLEUUID HARDWARE_REVISION_STRING_CHARACTERISTIC_UUID("2A27");
const NimBLEUUID SOFTWARE_REVISION_STRING_CHARACTERISTIC_UUID("2A28");
const NimBLEUUID MANUFACTURER_NAME_STRING_CHARACTERISTIC_UUID("2A29");
const NimBLEUUID IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_CHARACTERISTIC_UUID("2A2A");
const NimBLEUUID PNP_ID_CHARACTERISTIC_UUID("2A50");
const NimBLEUUID COUNTRY_CODE_CHARACTERISTIC_UUID("2AEC");
const NimBLEUUID DATE_UTC_CHARACTERISTIC_UUID("2AED");
const NimBLEUUID GLOBAL_TRADE_ITEM_NUMBER_CHARACTERISTIC_UUID("2AFA");
const NimBLEUUID UDI_FOR_MEDICAL_DEVICES_CHARACTERISTIC_UUID("2BFF");

class DateUTC {
  public:
    DateUTC(uint16_t year, uint8_t month, uint8_t day);
    operator uint32_t() const { return days_since_epoch; }
  private:
    uint32_t days_since_epoch;
};

/**
 * @brief Device Information Service class
 * @note This class implements the Bluetooth Device Information Service which provides device-specific information like manufacturer name, model number, serial number, firmware/hardware/software versions, etc.
 * @note For information about the Device Information Service, see https://www.bluetooth.com/specifications/specs/device-information-service/
 * @note For more information about the characteristics, see https://btprodspecificationrefs.blob.core.windows.net/device-properties/Device_Properties.pdf#page=24&zoom=100,96,733
 */
class BTDevInf {
  public:
    BTDevInf(NimBLEServer* server);
    bool startService();
    
    bool setSystemID(const uint8_t* system_id, size_t length);
    bool setModelNumberString(const std::string& model_number_string);
    bool setSerialNumberString(const std::string& serial_number_string);
    bool setFirmwareRevisionString(const std::string& firmware_revision_string);
    bool setHardwareRevisionString(const std::string& hardware_revision_string);
    bool setSoftwareRevisionString(const std::string& software_revision_string);
    bool setManufacturerNameString(const std::string& manufacturer_name_string);
    bool setIEEERegulatoryCertificationDataList(const uint8_t* data, size_t length);
    bool setPnPID(uint8_t vendor_id_source, uint16_t vendor_id, uint16_t product_id, uint16_t product_version);
    bool setCountryCode(uint16_t country_code);
    bool setDateOfManufacture(uint32_t days_since_epoch);
    bool setGlobalTradeItemNumber(uint64_t item_number);
    bool setUDIForMedicalDevices(const std::string& udi);
    
    NimBLEService* getService() { return device_info_service; }
    
    NimBLECharacteristic* getSystemIDCharacteristic() { return system_id_characteristic; }
    NimBLECharacteristic* getModelNumberCharacteristic() { return model_number_string_characteristic; }
    NimBLECharacteristic* getSerialNumberCharacteristic() { return serial_number_string_characteristic; }
    NimBLECharacteristic* getFirmwareRevisionCharacteristic() { return firmware_revision_string_characteristic; }
    NimBLECharacteristic* getHardwareRevisionCharacteristic() { return hardware_revision_string_characteristic; }
    NimBLECharacteristic* getSoftwareRevisionCharacteristic() { return software_revision_string_characteristic; }
    NimBLECharacteristic* getManufacturerNameCharacteristic() { return manufacturer_name_string_characteristic; }
    NimBLECharacteristic* getIEEERegulatoryCertificationDataListCharacteristic() { return ieee_regulatory_certification_data_list_characteristic; }
    NimBLECharacteristic* getPnPIDCharacteristic() { return pnp_id_characteristic; }
    NimBLECharacteristic* getCountryCodeCharacteristic() { return country_code_characteristic; }
    NimBLECharacteristic* getDateOfManufactureCharacteristic() { return date_of_manufacture_characteristic; }
    NimBLECharacteristic* getGlobalTradeItemNumberCharacteristic() { return global_trade_item_number_characteristic; }
    NimBLECharacteristic* getUDIForMedicalDevicesCharacteristic() { return udi_for_medical_devices_characteristic; }
    
  private:
    NimBLEService* device_info_service;
    
    NimBLECharacteristic* system_id_characteristic;
    NimBLECharacteristic* model_number_string_characteristic;
    NimBLECharacteristic* serial_number_string_characteristic;
    NimBLECharacteristic* firmware_revision_string_characteristic;
    NimBLECharacteristic* hardware_revision_string_characteristic;
    NimBLECharacteristic* software_revision_string_characteristic;
    NimBLECharacteristic* manufacturer_name_string_characteristic;
    NimBLECharacteristic* ieee_regulatory_certification_data_list_characteristic;
    NimBLECharacteristic* pnp_id_characteristic;
    NimBLECharacteristic* country_code_characteristic;
    NimBLECharacteristic* date_of_manufacture_characteristic;
    NimBLECharacteristic* global_trade_item_number_characteristic;
    NimBLECharacteristic* udi_for_medical_devices_characteristic;
    
    void setupDescriptors(NimBLECharacteristic* characteristic, const char* user_description, uint8_t format, int8_t exponent, uint16_t unit, uint8_t namespace_value, uint16_t description);
};

#endif // BTDEVINF_H