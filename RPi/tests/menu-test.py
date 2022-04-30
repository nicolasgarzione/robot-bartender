# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu

menu = Menu()

# A test script that tests whether a drink will
# be made correctly.

result = menu.get_recipe('Rum and Coke')
print(result)

result = menu.get_recipe('Screwdriver')
print(result)