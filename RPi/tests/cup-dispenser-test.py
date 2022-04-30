import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Command

command = Command()

command.serial.write(bytes(('C00000'+'\n').encode('utf-8')))