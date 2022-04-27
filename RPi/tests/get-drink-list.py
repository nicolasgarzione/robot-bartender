import os
import sys

sys.path.append(os.path.join(os.getcwd(),'RPi'))

from robotbartender import menu

menu1 = menu()

#print(menu1.drink_list)
#print(menu1.drink_menu)
#print(menu1.get_recipe('Margarita'))
menu1.get_drink_list()

'''
drink_path = os.path.join(os.getcwd(),'RPi','data','drink_list.csv')
drink_list = menu1.csv_reader(drink_path)

#print(drink_list)
dim = drink_list.shape
for i in range(1,dim[0],1):
    drink = drink_list[i,0]
    #print(drink)
    recipe = menu1.get_recipe(drink)
    if recipe != False:
        print(drink)
    
'''


