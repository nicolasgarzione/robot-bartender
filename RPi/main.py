from robotbartender import pv, menu, ser
from threading import Thread
from time import sleep
pv1 = pv()
menu1 = menu()
ser1 = ser()

print('hello?')

queue = []

class drinkMake(Thread):
    queue = []

    def __init__(self):
        Thread.__init__(self)
        self.daemon = True
        self.start()
        self.queue = []

    def run(self):
        while True:
            if self.queue:
             recipe = menu1.get_recipe(self.queue.pop(0))
             #print(self.queue)
             #print(recipe)
             ser1.send_recipe(recipe)
             sleep(1)


def main():
    print('running')
    while True:
        try:
            if pv1.drink != 'none':
                drink = pv1.drink.get('beverage')
                #print(pv1.drink.get('beverage'))
                make.queue.append(drink)
                pv1.drink = 'none'
                sleep(.1)
        except:
            sleep(.1)

if __name__ == '__main__':
    make = drinkMake()
    main()
