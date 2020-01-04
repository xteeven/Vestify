class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
    if(VERBOSE){
    Serial.println("onConnect");
    }
    connected = true;
    doScan = false;
  }

  void onDisconnect(BLEClient* pclient) {
    connected = false;
    doScan = true;
    if(VERBOSE){
    Serial.println("onDisconnect");
    }
  }
};




/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
 /**
   * Called for each advertising BLE server.
   */
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    if(VERBOSE){
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.toString().c_str());
    Serial.println(advertisedDevice.getAddress().toString().c_str());
    }
    String devicename = advertisedDevice.getAddress().toString().c_str();
    // We have found a device, let us now see if it contains the service we are looking for.

    if (devicename==desiredmac) {

      BLEDevice::getScan()->stop();
      myDevice = new BLEAdvertisedDevice(advertisedDevice);
      doConnect = true;
      doScan = true;
      
    } 
    else{
        doScan = true;
        }// Found our server
  } // onResult
}; // MyAdvertisedDeviceCallbacks
