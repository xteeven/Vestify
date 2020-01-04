
void loop() {
  if (deviceConnected) {
    // Fabricate some arbitrary junk for now...
    // txValue = analogRead(readPin) / 3.456; // This could be an actual sensor reading!
  
    // Let's convert the value to a char array:
    // char txString[8]; // make sure this is big enuffz
    // dtostrf(txValue, 1, 2, txString); // float_val, min_width, digits_after_decimal, char_buffer
    
    // pCharacteristic->setValue(&txValue, 1); // To send the integer value
    // pCharacteristic->setValue("Hello!"); // Sending a test message
    // pCharacteristic->setValue(txString);
    
    // pCharacteristic->notify(); // Send the value to the app!
    // Serial.print("*** Sent Value: ");
    // Serial.print(txString);
    // Serial.println(" ***");

  }

  if(amp>0 && !updating){MotorUpdate();}
    else{resetmotor();}


}

void MotorUpdate(){
unsigned long timeout = millis() - times;

  int amp2 = amp*2;
   for(int i = 2 ; i<8; i++)
    {
    if(motors[i-2]=='1'){
    tcaselect(i);
    float value = ((float)(timeout*frequency))/(1000.0f);
    float wave = ((float)amp2/2)+((float)amp2/2)*sin(value);
    LRA[i].setRealtimeValue(wave);
    }else
    {
      tcaselect(i);
      LRA[i].setRealtimeValue(0x00); 
      
      }
    }
    delay(20);
  }
