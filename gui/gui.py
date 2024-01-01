from tkinter import *
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
# Replace the port name with the serial port in use. On Linux (the pi) this will look like /dev/ttyUSB0 or something like that. You can run cat /dev/ | grep ttyUSB to find the port for now. will need a more robust solution for opening the serial connection.

def motor_up():
    print("motor up")
    ser.write(bytes("u", "utf-8"))
    ser.flush()

def motor_down():
    print("motor down")
    ser.write(bytes("d", "utf-8"))
    ser.flush()

def magnet_engage():
    print("magnet engage")
    ser.write(bytes("e", "utf-8"))
    ser.flush()

def magnet_disengage():
    print("magnet disengage")
    ser.write(bytes("r", "utf-8"))
    ser.flush()

root = Tk()

motor_up_button = Button(root, text="Motor Up", command=motor_up)
motor_up_button.pack()

motor_down_button = Button(root, text="Motor Down", command=motor_down)
motor_down_button.pack()

magnet_engage_button = Button(root, text="Magnet Engage", command=magnet_engage)
magnet_engage_button.pack()

magnet_disengage_button = Button(root, text="Magnet Disengage", command=magnet_disengage)
magnet_disengage_button.pack()

root.mainloop()
