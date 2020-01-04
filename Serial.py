import serial
import time
from serial import EIGHTBITS, PARITY_NONE, STOPBITS_ONE

class Vest(serial.Serial):
    def __init__(self, port=None, baudrate=115200, bytesize=EIGHTBITS, parity=PARITY_NONE, stopbits=STOPBITS_ONE, timeout=5, xonxoff=False, rtscts=False, write_timeout=None, dsrdtr=False, inter_byte_timeout=None, exclusive=None, **kwargs):
        super().__init__(port=port, baudrate=baudrate, bytesize=bytesize, parity=parity, stopbits=stopbits, timeout=timeout, xonxoff=xonxoff, rtscts=rtscts, write_timeout=write_timeout, dsrdtr=dsrdtr, inter_byte_timeout=inter_byte_timeout, exclusive=exclusive, **kwargs)
        self.amp = "00"
        self.freq = "00"
        self.activemotors = [0,0,0,0,0,0]

    def setAmplitude(self,amp=0):
        self.amp = str(int(amp)).zfill(2)

    def setFrequency(self, freq=10):
        self.freq = str(int(freq)).zfill(2)

    def setActiveMotors(self, motorVector):
        self.activemotors = motorVector

    def listToString(self, lista):
        output = ""
        for ele in lista:
            output += str(ele)
        return output

    def sendPattern(self):
        string = self.amp+";"+self.freq+";"+self.listToString(self.activemotors)
        self.write(bytes(string, 'utf-8'))

    def __del__(self):
        return super().__del__()
        print("close")
        self.close()
        

if __name__ == "__main__":
    port = '/dev/ttyUSB0'

    vest = Vest(port)


    #esp = serial.Serial(port,115200, timeout=5)

    vest.setAmplitude(23)
    vest.setFrequency(20)
    vest.setActiveMotors([0,0,0,1,1,1])

    vest.sendPattern()


    time.sleep(1)
    #esp.write(bytes("64;01;111111"+"\n", 'utf-8'))

    #esp.close()
