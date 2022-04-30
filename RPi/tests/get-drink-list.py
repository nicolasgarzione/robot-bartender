import sys
import os

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import Menu

menu = Menu()

menu.get_drink_list()


