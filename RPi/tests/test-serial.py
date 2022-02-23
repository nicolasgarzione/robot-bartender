import serialCommand
import serial

def main():
    ser = serial.Serial('/dev/ttyUSB0')
    command = serialCommand(ser)
    command.push_packet('CM',255)
    command.push_packet('CA',0)
    command.send_packet()

if __name__ == "__main__":
    main()