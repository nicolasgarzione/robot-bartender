import serial

class serialCommand():

    __ser = None
    __names = []
    __values = []

    def __init__(self, serialSet):
        self.__ser = serialSet

    def search(self, list, to_find):
        temp_list = list.copy()
        temp_to_find = to_find.copy()
        for i in range(len(temp_list)):
            if temp_list[i] == temp_to_find:
                return True
        return False

    def push_to_packet(self, name, value):
        temp_name = name.copy()
        temp_value = value.copy()
        if self.search(self.__names, temp_name):
            index = self.__names(temp_name)
            self.__values[index] = temp_value
        else:
            self.__names.append(temp_name)
            self.__values.append(temp_value)
        
    def send_packet(self):
        temp = '%'
        for i in range(len(self.__names)):
            temp + self.__names[i] + str(hex(self.__value[i])) + ','
        temp - ','
        temp + ';'
        self.__ser.write(temp)
        self.clear_packet

    def clear_packet(self):
        self.__names = []
        self.__values = []