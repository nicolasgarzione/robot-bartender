# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu

menu = Menu()

# A test script to see the current avaliable drinks
# that can be made.

menu.get_drink_list()


