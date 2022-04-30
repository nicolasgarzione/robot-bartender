import sys
import os
from time import sleep

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Command

command = Command()

while stop == False:
            command.serial.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.5)
            try:
                recieved = command.serial.readline().decode('utf-8').rstrip()
            except:
                recieved = '0'
            command.serial.flush()
            if recieved == '1':
                command.serial.flush()
                sleep(0.1)
                print('done')
                stop = True