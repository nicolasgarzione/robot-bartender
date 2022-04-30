from serial import Serial
import struct

# An outdated test to try efficient UART communication method.
# Original intent was to try a method of serial communication
# to take advantage of Teensy communication capabilities.
# This ended up being uneeded for this project. 

serial = Serial('/dev/ttyUSB0', 115200, 8, 'N', 1)  
print(serial.isOpen())

serial.flushInput()
serial.flushOutput()

while (1):
    byte = struct.unpack('B', serial.read(1))[0]
    if (byte == 0xFE):
        byte2 = struct.unpack('B', serial.read(1))[0]
        byte3 = struct.unpack('B', serial.read(1))[0]
        byte4 = struct.unpack('B', serial.read(1))[0]
        byte5 = struct.unpack('B', serial.read(1))[0]
        byte6 = struct.unpack('B', serial.read(1))[0]
        header = byte
        version_id = byte2
        lsb_byte = byte3
        msb_byte = byte4
        snr = byte5
        check_sum_transmitter = byte6
        check_sum_receiver = (byte2 + byte3 + byte4 + byte5) & 0xFF
        MESSAGE = byte3 + (byte4 << 8)

        if (check_sum_receiver == check_sum_transmitter):
            if (MESSAGE > 0):
                print("checksum passed and altitude data is valid!  Altitude:  " + str(MESSAGE) + ", SNR:" + str(snr) + '\r\n'"")
            else:
                print ("checksum passed, but altitude data is not valid! ")
        else:
            print ("checksum failed!!!" + '\r\n')
    else:
        continue