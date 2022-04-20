import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu

menu1 = menu()

result = menu1.get_recipe('Rum and Coke')
print(result)

result = menu1.get_recipe('Screwdriver')
print(result)