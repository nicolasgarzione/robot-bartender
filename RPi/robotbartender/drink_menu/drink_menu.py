import os
import sys
import csv
import numpy as np
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)

class drink_menu:
    def __init__(self):
        tap_path = os.path.join(os.getcwd(),'RPi','data','on_tap.csv')
        on_tap = self.csv_reader(tap_path)

        drink_path = os.path.join(os.getcwd(),'RPi','data','drink_list.csv')
        drink_list = self.csv_reader(drink_path)
        self.drink_list = drink_list

        shortened_drink_list = self.csv_cut(drink_list, on_tap)
        ordered_drink_list = self.csv_order(shortened_drink_list, on_tap)

        self.drink_menu = ordered_drink_list

    def csv_reader(self, filename):
        reader = csv.reader(open(filename, "r"), delimiter=",")
        x = list(reader)
        result = np.array(x)

        return result

    def csv_cut(self, twoD_list, oneD_list):
        two_list = np.copy(twoD_list)
        i = 1
        while i < oneD_list.size:
            if two_list[0,i] in oneD_list[0,:]:
                i = i + 1
            else:
                temp = np.delete(two_list, i, 1)
                two_list = temp

        return two_list

    def csv_order(self, twoD_list, oneD_list):
        dim = twoD_list.shape
        position = [0]
        i = 0
        while i < oneD_list.size:
            j = 1
            while j < dim[1]:
                if twoD_list[0,j] == oneD_list[0,i]:
                    position.append(j)
                    break
                else:
                    j = j + 1  
            i = i + 1

        return twoD_list[:,position]

    def get_recipe(self, drink):
        if drink in self.drink_list[:,0]:
            index = np.where(self.drink_menu[:,0] == drink)
            dim1 = self.drink_menu.shape
            dim2 = self.drink_list.shape
            #print(self.drink_menu[index,1:dim1[1]-1])
            #print(self.drink_list[index,1:dim2[1]-1])
            comparearray1 = self.drink_menu[index,1:dim1[1]].astype(float)
            #print(comparearray1)
            comparearray2 = self.drink_list[index,1:dim2[1]-1].astype(float)
            #print(comparearray2)
            if np.sum(comparearray1) == np.sum(comparearray2):
                return self.drink_menu[index,1:None]
            else:
                return False
        else:
            return False

    def get_drink_list(self):
        dim = self.drink_list.shape
        for i in range(1,dim[0],1):
            #print(self.drink_list[i,0])
            drink = self.drink_list[i,0]
            recipe = self.get_recipe(drink)
            if recipe != False:
                print(drink)
            

