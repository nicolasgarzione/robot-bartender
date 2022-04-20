import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu, ser

ser1 = ser()
menu1 = menu()

recipe = menu1.get_recipe('Screwdriver')

ser1.send_serial(recipe)
