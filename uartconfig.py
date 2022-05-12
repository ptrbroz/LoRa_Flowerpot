import serial
import time
from time import sleep

ser = serial.Serial('COM4', 115200) #replace with your com port

mode = 0;
soilTarget = 0;
tempTarget = 0;    

mask = 0xff;
soilLow = soilTarget & mask
soilHigh = (soilTarget >> 8) & mask

header = 100
ser.write(header.to_bytes(1, 'little'))
ser.write(header.to_bytes(1, 'little'))
ser.write(header.to_bytes(1, 'little'))
ser.write(header.to_bytes(1, 'little'))
ser.write(header.to_bytes(1, 'little'))

ser.write(mode.to_bytes(1, 'little'))
ser.write(soilLow.to_bytes(1 , 'little'))
ser.write(soilHigh.to_bytes(1, 'little'))
ser.write(tempTarget.to_bytes(1, 'little'))


while(1):
    print(ser.readline())
