# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

from picovoicebartender import PV
from drinkmenu import Menu
from serialcommand import Command
from threading import Thread
from time import sleep

pv = PV()
menu = Menu()
command = Command()

class MakeDrink(Thread):
    # A thread that maintains a queue of drinks that have been ordered
    # so far. The drink is verified and if it is able to be made, it is
    # then sent to the serial command package.  
    queue = []

    def __init__(self):
        Thread.__init__(self)
        self.daemon = True
        self.start()
        self.queue = []

    def run(self):
        while True:
            if self.queue:
                recipe = menu.get_recipe(self.queue.pop(0))
                if recipe != False:
                    command.send_recipe(recipe)
                else:
                    print('That drink is not avaliable')
                    sleep(1)


def main():
    # The main function constantly checks if a drink has been ordered.
    # When a drink has been ordered, it is sent to the MakeDrink thread
    # to be processed.
    menu.get_drink_list()
    while True:
        try:
            if pv.drink != 'none':
                drink = pv.drink.get('beverage')
                make.queue.append(drink)
                pv.drink = 'none'
                sleep(.1)
        except:
            sleep(.1)

if __name__ == '__main__':
    make = MakeDrink()
    main()
