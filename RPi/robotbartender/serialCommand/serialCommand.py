import serial
from time import sleep
import numpy as np
from threading import Thread

class serialCommand(Thread):

    __port = 'COM8'

    def __init__(self):
        ser = serial.Serial(self.__port, baudrate=9600)

        while True:
            ret = False
            while ret == False:
                print('trying...')
                ret = self.try_to_open_new_port()
            print('did I get here?')
            ser.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.03)
            print('what about here?')
            try:
                recieved = ser.readline().decode('utf-8').rstrip()
            except:
                recieved = '0'
            print('here?')
            print(recieved)
            if recieved == '1':
                print('probbaly not here?')
                ser.write(bytes(('A00000'+'\n').encode('utf-8')))
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

        self.ser.write(bytes(('A00000'+'\n').encode('utf-8')))

        for x in range(0, length-1, 1):
            command = self.serial_command(command_list[0,x],x+1) + '\n'
            self.ser.write(bytes(command.encode('utf-8')))
            self.ser.write(bytes(('Z00000'+'\n').encode('utf-8')))

    def serial_command(self, input, index):
        if input == "mix" or input == "cup" or input == "ice":
            if input == "cup":
                string_to_send = 'C00000'
            elif input == "mix":
                string_to_send = 'D00000'
            elif input == "ice":
                string_to_send = 'E00000'
        else:
            if index > 9:
                index_input = str(index)
            else:
                index_input = '0'+str(index)
            string_to_send = 'B'+str(input*100)+index_input

        return string_to_send

    def rotate_command(self, numofturns):
        pass

    def try_to_open_new_port(self):
        ret = False
        test = serial.Serial(baudrate=9600, timeout=0, writeTimeout=0)
        test.port = self.__port
        try:
            test.open()
            if test.isOpen():
                test.close()
                ret = True
        except serial.serialutil.SerialException:
            pass
        return ret



