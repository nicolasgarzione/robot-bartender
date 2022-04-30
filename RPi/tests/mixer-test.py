# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Command

command = Command()

# A test script for the mixer. One serial packet is
# sent to activate it.

command.serial.write(bytes(('D00000'+'\n').encode('utf-8')))