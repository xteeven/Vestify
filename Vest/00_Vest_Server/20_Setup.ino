void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  // Create the BLE Device
  BLEDevice::init(nameOfTheVest); // Give it a name

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
                      
  pCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RX,
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  //Serial.println("Waiting a client connection to notify...");




  for(int actuator=0;actuator<LRANum;actuator++){
     tcaselect(actuator);
     LRA[actuator].begin();
     LRA[actuator].selectLibrary(6);
      
      // I2C trigger by sending 'go' command 
      // default, internal trigger when sending GO command
      //LRA[actuator].setMode(DRV2605_MODE_INTTRIG); 
      LRA[actuator].setMode(DRV2605_MODE_REALTIME);
      LRA[actuator].useLRA();
        }
        times= millis();
  
}
