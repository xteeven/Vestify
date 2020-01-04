class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();
      updating = true;
      if (rxValue.length() > 0) {

        String msg = rxValue.c_str();

        // Do stuff based on the command received from the app
        if(rxValue.length()==12){
          
          SetValues(msg.substring(0, 2).toInt(),msg.substring(3, 5).toInt(),msg.substring(6, 12));
        
        }

        
      }
      updating=false;
    }
};


void SetValues(int ampt, int frequencyt, String motorst){
  
  amp = ampt;
  frequency = frequencyt;
  motors = motorst;
  
  }
