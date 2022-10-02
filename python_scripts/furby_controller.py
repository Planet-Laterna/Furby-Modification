import time
import serial
from getkey import getkey, keys


# script based on example under https://www.varesano.net/serial-rs232-connections-in-python/ using python 3
# adapted to use keystrokes without pressing "Enter" key
# in order to use this script you need to install pyserial and getKey package

# configure Furby controller serial interface
ser = serial.Serial(
	port='/dev/ttyACM7',   # Replace this port with the one detected at your PC e.g ttyUSB0,ttyUSB0 ...',
	baudrate=9600,
	parity=serial.PARITY_ODD,
	stopbits=serial.STOPBITS_TWO,
	bytesize=serial.SEVENBITS
)

#ser.open()
if ser.isOpen():
    print ('Connection to target Furby ok!')
    print ('Enter your commands below.\r\n Insert "q" to leave the application.')

else:
    print('it was not possible to open port, check if device connected, ports is used by other appplication or port name')

enteredkey=1
feedback=str(ser.readline())
print (feedback)    #Check Controller feedback

while 1 :
    # get keyboard input
    # #response = input(">> ")
    enteredkey = getkey()
    
    if ( enteredkey == "q"):
        ser.close()
        exit()
    else:
        # send the character to the device including \r\n carriage return and line feed to the characters
        command = enteredkey #+ '\r\n'
        print ("This is the command I send")
        print (command)

        ser.write(command.encode())

        #For debugging purpuses
        # check which command was sent
        feedback=str(ser.readline())
        print(feedback)
        # check if command was executed
        feedback=str(ser.readline())
        print(feedback)

        # case help , fetch the feedback
        if (enteredkey == "p"):
            while 1:
                feedback=str(ser.readline())
                print(feedback)

                if (feedback == "b'end\\r\\n'"):
                    print('reached end')
                    break