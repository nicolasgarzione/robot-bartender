import sys
import os
import numpy as np

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu
from robotbartender import Command

command = Command()
menu = Menu()

recipe = np.array([['1' '1' '1' '0' '1' '1' '1' '1' '1' '1' '1' '1']])

command.send_recipe(recipe)