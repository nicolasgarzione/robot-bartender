# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import os
import csv
import numpy as np
import warnings

warnings.simplefilter(action='ignore', category=FutureWarning)

# A package that formulates drink recipes given a CSV of
# drink recipes and a CSV of the drinks currently on tap. 
#
# The purpose of this package is to rearrange the recipes
# so that they: will follow the order the drinks are in on 
# the bartender and not allow drinks to be made if not all
# the ingredients are present.

class DrinkMenu:
    def __init__(self):
        # Imports the two CSVs needed and executes all functions
        # necessary to provide refined drink menu.
        tap_path = os.path.join(os.getcwd(),'RPi','data','on_tap.csv')
        on_tap = self.csv_reader(tap_path)

        drink_path = os.path.join(os.getcwd(),'RPi','data','drink_list.csv')
        drink_list = self.csv_reader(drink_path)
        self.drink_list = drink_list

        shortened_drink_list = self.csv_cut(drink_list, on_tap)
        ordered_drink_list = self.csv_order(shortened_drink_list, on_tap)

        self.drink_menu = ordered_drink_list

    def csv_reader(self, filename):
        # A function to read CSVs in to NumPy arrays
        reader = csv.reader(open(filename, "r"), delimiter=",")
        x = list(reader)
        result = np.array(x)

        return result

    def csv_cut(self, two_d_list, one_d_list):
        # A function to cut down the recipe book
        # to only include the ingredients on tap.
        two_list = np.copy(two_d_list)
        i = 1
        while i < one_d_list.size:
            if two_list[0,i] in one_d_list[0,:]:
                i = i + 1
            else:
                temp = np.delete(two_list, i, 1)
                two_list = temp

        return two_list

    def csv_order(self, two_d_list, one_d_list):
        # A function to order the cut down recipe
        # book to be in the order of the drinks on 
        # tap.
        dim = two_d_list.shape
        position = [0]
        i = 0
        while i < one_d_list.size:
            j = 1
            while j < dim[1]:
                if two_d_list[0,j] == one_d_list[0,i]:
                    position.append(j)
                    break
                else:
                    j = j + 1  
            i = i + 1

        return two_d_list[:,position]

    def get_recipe(self, drink):
        # Determines if recipe can be made and if so it 
        # returns it.
        if drink in self.drink_list[:,0]:
            index = np.where(self.drink_menu[:,0] == drink)
            dim1 = self.drink_menu.shape
            dim2 = self.drink_list.shape
            comparearray1 = self.drink_menu[index,1:dim1[1]].astype(float)
            comparearray2 = self.drink_list[index,1:dim2[1]-1].astype(float)
            if np.sum(comparearray1) == np.sum(comparearray2):
                return self.drink_menu[index,1:None]
            else:
                return False
        else:
            return False

    def get_drink_list(self):
        # Lists all drinks that can be made
        # wth the curent ingredients
        dim = self.drink_list.shape
        for i in range(1,dim[0],1):
            drink = self.drink_list[i,0]
            recipe = self.get_recipe(drink)
            if recipe != False:
                print(drink)
            

