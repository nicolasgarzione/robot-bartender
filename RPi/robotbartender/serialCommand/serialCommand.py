#import serial
from time import sleep
import numpy as np

class serialCommand():

    def __init__(self):
        #ser = serial.Serial('/dev/ttyUSB0', baudrate=9600)
        #while True:
        #    ser.write('Z00000\n')
        #    sleep(0.03)
        #    recieved = ser.read()
        #    if recieved == 1:
        #        break
        pass

    def send_serial(self, recipe):
        index = 0
        list_temp = list()
        list_temp.append("cup")
        list_temp.append("ice")
        for x in range(0,recipe.size-1,1):
            list_temp.append(recipe[0,0,x].tolist())
        list_temp.append("mix")
        list_temp.append('0')
        for x in range(0,4+recipe.size-1):
            print(list_temp[x])

        command_list = list_temp
        length = len(command_list)

        for x in range(0, length-1, 1):

    def serial_command(self, input):
        if input == "mix" or input == "cup" or input == "ice":

        else:
            


