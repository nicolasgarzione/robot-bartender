import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu, ser

ser1 = ser()

ser.ser.write(bytes(('A00000'+'\n').encode('utf-8')))