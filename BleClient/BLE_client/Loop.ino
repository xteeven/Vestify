
// This is the Arduino main loop function.
void loop() {
  digitalWrite(LED_BUILTIN,connected);
  if(VERBOSE){
  Serial.print(doScan);
  Serial.println(connected);
  }

  Connect();
  // If we are connected to a peer BLE Server, update the characteristic each time we are reached
  // with the current time since boot.
  if (connected) {
    if(VERBOSE){
    Serial.println("Setting new");
    }

    Handler();
    // Set the characteristic's value to be the array of bytes that is actually a string.
    //pRemoteCharacteristic->writeValue(newValue.c_str(), newValue.length());
  }else if(doScan){
    delay(100);
    BLEDevice::getScan()->start(0);  // this is just eample to start scan after disconnect, most likely there is better way to do it in arduino
  }
  

} // End of loop

void Connect(){
  
    // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are 
  // connected we set the connected flag to be true.
  
  if (doConnect) {
    digitalWrite(LED_BUILTIN,HIGH);
    if (connectToServer()) {
      if(VERBOSE){
      Serial.println("We are now connected to the BLE Server.");
      }
    } else {
      if(VERBOSE){
      Serial.println("We have failed to connect to the server; there is nothin more we will do.");
      }
      digitalWrite(LED_BUILTIN,LOW);
    }
    doConnect = false;
  }
  
  }

  void Handler(){
    
    
    if (Serial.available() > 0) {
        String msg = Serial.readStringUntil('\n');
        if (msg){
          pRemoteCharacteristic->writeValue(msg.c_str(), msg.length());
        digitalWrite(LED_BUILTIN,LOW);
        //delay(1000);
        }
      }else{
        
        }
    
    
    }
