#outdated test to try efficient UART communication method

from serial import Serial
import struct

serial = Serial('/dev/ttyUSB0', 115200, 8, 'N', 1)  ### This serial port name may be various on OS or machine
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
        ALTITUDE = byte3 + (byte4 << 8)

        ### Print received data
        if (check_sum_receiver == check_sum_transmitter):
            if (ALTITUDE > 0):
                print("checksum passed and altitude data is valid!  Altitude:  " + str(ALTITUDE) + ", SNR:" + str(snr) + '\r\n'"")
            else:
                print ("checksum passed, but altitude data is not valid! ")
        else:
            print ("checksum failed!!!" + '\r\n')
    else:
        continue