# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu
from robotbartender import Command

menu = Menu()
command = Command()

# A test script to test full functionality excluding
# voice recognition.

menu.get_drink_list()
recipe = menu.get_recipe('Whiskey Coke')
print(recipe)

input('press enter')

command.send_recipe(recipe)
