void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void playmotor(int amp, int frequency, String motors){



times = millis();
unsigned long timeout = millis() - times;

amp= amp*2;
while( timeout < 2000){
  for(int i = 2 ; i<8; i++)
    {
    if(motors[i-2]=='1'){
    tcaselect(i);
    float value = ((float)(timeout*frequency))/(1000.0f);
    float wave = ((float)amp/2)+((float)amp/2)*sin(value);
    LRA[i].setRealtimeValue(wave);
    }else
    {
      tcaselect(i);
      LRA[i].setRealtimeValue(0x00); 
      
      }
    }
    delay(20);
  timeout = millis() - times;
}


    
}


void resetmotor(){
    for(int i = 2 ; i<8; i++)
  {

  tcaselect(i);
  delay(20);
  LRA[i].setRealtimeValue(0x00);  
  }
  }
