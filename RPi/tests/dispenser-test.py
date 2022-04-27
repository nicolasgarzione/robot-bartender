import sys
import os
import numpy as np

sys.path.append(os.path.join(os.getcwd(),'RPi'))

print('hello')

from robotbartender import menu, ser

print('hello')

ser1 = ser()
menu1 = menu()

print('hello')

recipe = np.array([['1' '1' '1' '0' '1' '1' '1' '1' '1' '1' '1' '1']])
print(recipe)

input('press enter')

ser1.send_recipe(recipe)