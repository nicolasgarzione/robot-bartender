import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu
from robotbartender import Command

menu = Menu()
command = Command()


menu.get_drink_list()
recipe = menu.get_recipe('Whiskey Coke')
print(recipe)

input('press enter')

command.send_recipe(recipe)
