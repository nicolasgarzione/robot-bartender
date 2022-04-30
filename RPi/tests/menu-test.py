import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu

menu = Menu()

result = menu.get_recipe('Rum and Coke')
print(result)

result = menu.get_recipe('Screwdriver')
print(result)