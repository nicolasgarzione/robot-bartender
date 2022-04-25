import serial
from time import sleep
import numpy as np
from threading import Thread

class serialCommand(Thread):

    __port = 'COM8'

    def __init__(self):
        self.ser = serial.Serial(self.__port, 9600)
        sleep(1)
        stop = False
        recieved = '0'

        while stop == False:
            #ret = False
            #while ret == False:
            #    print('trying...')
            #    ret = self.try_to_open_new_port()
            #print('did I get here?')
            self.ser.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.5)
            #print('what about here?')
            try:
                recieved = self.ser.readline().decode('utf-8').rstrip()
                #print(self.ser.readline())
            except:
                recieved = '0'
            self.ser.flush()
            #print('here?')
            #print(recieved)
            if recieved == '1':
                #print('probbaly not here?')
                self.ser.write(bytes(('A00000'+'\n').encode('utf-8')))
                stop = True

    def send_recipe(self, recipe):
        index = 0
        list_temp = list()
        list_temp.append("cup")
        list_temp.append("ice")
        for x in range(0,recipe.size,1):
            list_temp.append(recipe[0,0,x].tolist())
        list_temp.append("mix")
        #for x in range(0,3+recipe.size-1,1):
            #print(list_temp[x])

        command_list = list_temp
        print(command_list)
        length = len(command_list)

        self.serial_send('A00000'+'\n')

        for x in range(0, length, 1):
            command = self.serial_command(command_list[x],x+1) + '\n'
            self.serial_send(command)
            self.serial_send('A00000'+'\n')

    def serial_command(self, input, index):
        if input == "mix" or input == "cup" or input == "ice":
            if input == "cup":
                string_to_send = 'C00000'
            elif input == "mix":
                string_to_send = 'D00000'
            elif input == "ice":
                string_to_send = 'E00000'
        else:
            index -= 3
            if index > 9:
                index_input = str(index)
            else:
                index_input = '0'+str(index)
            print(input)
            int_input = int(input)
            int_input *= 100
            print(input)
            print(index)
            if int_input == 0:
                string_to_send = 'B'+'00'+str(int_input)+index_input
            else:
                string_to_send = 'B'+str(int_input)+index_input
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

    def serial_send(self, command):
        print(f'sending: {command}')
        recieved = '0'
        self.ser.write(bytes(command.encode('utf-8')))
        while recieved == '0':
            recieved = self.ser.readline().decode('utf-8').rstrip()




