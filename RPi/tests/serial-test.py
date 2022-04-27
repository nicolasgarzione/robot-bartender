import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu, ser

ser1 = ser()
menu1 = menu()

menu1.get_drink_list()
recipe = menu1.get_recipe('Whiskey Coke')
print(recipe)

input('press enter')

ser1.send_recipe(recipe)
