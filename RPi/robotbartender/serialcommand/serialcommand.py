<<<<<<< HEAD:RPi/robotbartender/serialCommand/serialCommand.py
# Author: Nicolas Garzione
# Robot Bartender
# 4/30/2022

import serial
from time import sleep
from threading import Thread

# A package to handle all serial communication with the
# Teensy microcontroller. 

class SerialCommand(Thread):
    # Serial packets take the form: # A12345
    #
    # A : subsystem being called
    # 123 : value being sent
    # 45 : identifier within subsystem
    #
    # The subsystems for this project are:
    #
    # A : table rotate
    # B : drink dispense
    # C : cup disepense
    # D : mixer
    # E : ice dispense
    # X : throw error
    # z : ping

    __port = 'COM8' # Specific to windows computer

    def __init__(self):
        # Establishes the serial communication and pings
        # the Teensy.
        print('started')
        self.serial = serial.Serial(self.__port, 9600)
        sleep(1) # Necessary to wait for serial communication to establish 
        stop = False
        recieved = '0'

        while stop == False:
            self.serial.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.5)
            try:
                recieved = self.serial.readline().decode('utf-8').rstrip()
            except:
                recieved = '0'
            self.serial.flush()
            if recieved == '1':
                stop = True

    def send_recipe(self, recipe):
        # Builds array of commands to be sent to the Teensy.
        # These commands are then sent one by one to the 
        # Teensy and waits for its response after every
        # command sent.
        list_temp = list()
        list_temp.append("cup")
        list_temp.append("ice")
        for x in range(0,recipe.size,1):
            list_temp.append(recipe[0,0,x].tolist())
        list_temp.append("mix")

        command_list = list_temp
        length = len(command_list)

        self.serial_send('A00000'+'\n')

        for x in range(0, length, 1):
            command = self.serial_command(command_list[x],x+1) + '\n'
            self.serial_send(command)
            if command == 'cup':
                self.serial_send('A00000'+'\n')
            self.serial_send('A00000'+'\n')

    def serial_command(self, input, index):
        # Determines what packet should be sent given a command.
        if input == "mix" or input == "cup" or input == "ice":
            if input == "cup":
                string_to_send = 'C00000'
            elif input == "mix":
                string_to_send = 'D00000'
            elif input == "ice":
                string_to_send = 'E00000'
        else:
            index -= 2
            if index > 9:
                index_input = str(index)
            else:
                index_input = '0' + str(index)
            int_input = int(input)
            int_input *= 100
            if int_input == 0:
                string_to_send = 'B' + '00' + str(int_input) + index_input
            else:
                string_to_send = 'B' + str(int_input) + index_input
        return string_to_send

    def serial_send(self, command):
        # Sends packet to the Teensy and waits
        # for a response.
        print(f'sending: {command}')
        recieved = '0'
        self.serial.write(bytes(command.encode('utf-8')))
        while recieved == '0':
            recieved = self.serial.readline().decode('utf-8').rstrip()
        print('done')
        




=======
import serial
from time import sleep
from threading import Thread

class SerialCommand(Thread):

    __port = 'COM8'

    def __init__(self):
        print('started')
        self.serial = serial.Serial(self.__port, 9600)
        sleep(1)
        stop = False
        recieved = '0'

        while stop == False:
            self.serial.write(bytes(('Z00000'+'\n').encode('utf-8')))
            sleep(0.5)
            try:
                recieved = self.serial.readline().decode('utf-8').rstrip()
            except:
                recieved = '0'
            self.serial.flush()
            if recieved == '1':
                stop = True

    def send_recipe(self, recipe):
        list_temp = list()
        list_temp.append("cup")
        list_temp.append("ice")
        for x in range(0,recipe.size,1):
            list_temp.append(recipe[0,0,x].tolist())
        list_temp.append("mix")

        command_list = list_temp
        length = len(command_list)

        self.serial_send('A00000'+'\n')

        for x in range(0, length, 1):
            command = self.serial_command(command_list[x],x+1) + '\n'
            self.serial_send(command)
            if command == 'cup':
                self.serial_send('A00000'+'\n')
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
            index -= 2
            if index > 9:
                index_input = str(index)
            else:
                index_input = '0'+str(index)
            int_input = int(input)
            int_input *= 100
            if int_input == 0:
                string_to_send = 'B'+'00'+str(int_input)+index_input
            else:
                string_to_send = 'B'+str(int_input)+index_input
        return string_to_send

    def serial_send(self, command):
        print(f'sending: {command}')
        recieved = '0'
        self.serial.write(bytes(command.encode('utf-8')))
        while recieved == '0':
            recieved = self.serial.readline().decode('utf-8').rstrip()
        print('done')
        




>>>>>>> c00c187364ad38fa70337fe2e5e05ca6fcb3dda2:RPi/robotbartender/serialcommand/serialcommand.py
