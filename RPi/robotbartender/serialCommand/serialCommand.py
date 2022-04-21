import serial
from time import sleep
import numpy as np

class serialCommand():

    def __init__(self):
        ser = serial.Serial('/dev/ttyUSB0', baudrate=9600)
        while True:
            ser.writeln('Z00000')
            sleep(0.03)
            recieved = ser.read()
            if recieved == 1:
                ser.writeln('A00000')
                break

    def send_serial(self, recipe):
        index = 0
        list_temp = list()
        list_temp.append("cup")
        list_temp.append("ice")
        for x in range(0,recipe.size-1,1):
            list_temp.append(recipe[0,0,x].tolist())
        list_temp.append("mix")
        for x in range(0,4+recipe.size-1):
            print(list_temp[x])

        command_list = list_temp
        length = len(command_list)

        self.ser.writeln('A00000')

        for x in range(0, length-1, 1):
            self.serial_command(command_list[0,x],x+1)
            self.ser.writeln('A00000')

    def serial_command(self, input, index):
        if input == "mix" or input == "cup" or input == "ice":
            if input == "cup":
                string_to_send = "C00000"
            elif input == "mix":
                string_to_send = "D00000"
            elif input == "ice":
                string_to_send = "E00000"
        else:
            if index > 9:
                index_input = str(index)
            else:
                index_input = "0"+str(index)
            string_to_send = "B"+str(input*100)+index_input

        return string_to_send

    def rotate_command(self, numofturns):
        pass



