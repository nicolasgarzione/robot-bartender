import sys
import os
from time import sleep

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import ser

ser1 = ser()

ser.ser.write(bytes(('B10001'+'\n').encode('utf-8')))

recieved = ser.ser.readline().decode('utf-8').rstrip()

print(recieved)