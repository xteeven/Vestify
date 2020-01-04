bool connectToServer() {
  if(VERBOSE){
    Serial.print("Forming a connection to ");
    Serial.println(myDevice->getAddress().toString().c_str());
  }
    BLEClient*  pClient  = BLEDevice::createClient();
    if(VERBOSE){
    Serial.println(" - Created client");
    }
    pClient->setClientCallbacks(new MyClientCallback());

    // Connect to the remove BLE Server.
    pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
    if(VERBOSE){
    Serial.println(" - Connected to server");
    }
    // Obtain a reference to the service we are after in the remote BLE server.
    if(pClient->isConnected()){}else{return false;}
      
      BLERemoteService* pRemoteService = pClient->getService(serviceUUID); // SOMETHING BLOCKING
      
    
    if (pRemoteService == nullptr) {
      if(VERBOSE){
      Serial.print("Failed to find our service UUID: ");
      Serial.println(serviceUUID.toString().c_str());
      }
      pClient->disconnect();
      return false;
    }
    if(VERBOSE){
    Serial.println(" - Found our service");
    }

    // Obtain a reference to the characteristic in the service of the remote BLE server.
    pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);

    if (pRemoteCharacteristic == nullptr) {
      if(VERBOSE){
      Serial.print("Failed to find our characteristic UUID: ");
      Serial.println(charUUID.toString().c_str());
      }
      pClient->disconnect();
      return false;
    }
    if(VERBOSE){
    Serial.println(" - Found our characteristic");
    }
    // Read the value of the characteristic.
    if(pRemoteCharacteristic->canRead()) {
      std::string value = pRemoteCharacteristic->readValue();
      if(VERBOSE){
      Serial.print("The characteristic value was: ");
      Serial.println(value.c_str());
      }
    }

    if(pRemoteCharacteristic->canNotify())
      pRemoteCharacteristic->registerForNotify(notifyCallback);

    connected = true;
    return true;
}
