import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu, ser

ser1 = ser()
menu1 = menu()

recipe = [[['1' '1' '1' '1' '1' '1' '1' '1' '1' '1' '1' '1']]]
print(recipe)

input('press enter')

ser1.send_recipe(recipe)