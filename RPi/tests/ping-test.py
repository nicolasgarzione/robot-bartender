import sys
import os
from time import sleep

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu, ser

ser1 = ser()

while stop == False:
            ser.ser.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.5)
            try:
                recieved = ser.ser.readline().decode('utf-8').rstrip()
            except:
                recieved = '0'
            ser.ser.flush()
            if recieved == '1':
                ser.ser.flush()
                sleep(0.1)
                print('done')
                stop = True