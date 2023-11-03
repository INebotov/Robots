import serial


class Serial:
    def __init__(self, port, bort=9600):
        self.ser = serial.Serial(port, bort, timeout=5)

    def Send(self, data):
        self.ser.write(data)
