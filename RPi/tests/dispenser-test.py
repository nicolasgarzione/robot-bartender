# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os
import numpy as np

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu
from robotbartender import Command

command = Command()
menu = Menu()

# A test script to actuate every cup dispenser to verify 
# their fuctionality

recipe = np.array([['1' '1' '1' '0' '1' '1' '1' '1' '1' '1' '1' '1']])

command.send_recipe(recipe)