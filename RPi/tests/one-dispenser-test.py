# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os
from time import sleep

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Command

command = Command()

# A test script for the drink dispenser. One serial packet is
# sent to activate it.

command.serial.write(bytes(('B10001'+'\n').encode('utf-8')))

recieved = command.serial.readline().decode('utf-8').rstrip()

print(recieved)