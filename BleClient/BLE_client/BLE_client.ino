/**
BLE Client: 
This code performs the communication Vest-PC, using the serial port

**/

#include "BLEDevice.h"

// Debug Serial
#define VERBOSE 1

// The remote service we wish to connect to.
static BLEUUID serviceUUID("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");


// MAC addres of the vest,
//Segundo "24:0a:c4:a6:08:76" (Melanie)
//Primero "30:ae:a4:f5:21:52" (Steeven)

static String desiredmac = "24:0a:c4:a6:08:76";

// Runtime Variables
static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;

static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
    if(VERBOSE){
    Serial.print("Notify callback for characteristic ");
    Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
    Serial.print(" of data length ");
    Serial.println(length);
    Serial.print("data: ");
    Serial.println((char*)pData);
    }
}
