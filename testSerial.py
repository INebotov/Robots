import serial
import time
import struct


class MotorsValues:
    D11: bool = False
    D12: bool = False
    D21: bool = False
    D22: bool = False

    P1: int = 0
    P2: int = 0

    Shoot: bool = False

    def ToBytes(self) -> bytes:
        # Define the format string for packing the data
        format_string = 'c c ? ? ? ? ?'
        data = (
            bytes([self.P1]),
            bytes([self.P2]),
            self.D11,
            self.D12,
            self.D21,
            self.D22,
            self.Shoot
        )

        # Pack the data into bytes
        packed_data = struct.pack(format_string, *data)
        return packed_data


# Example usage:
motor_values = MotorsValues()
motor_values.P1 = 42
motor_values.P2 = 126
motor_values.D11 = True
motor_values.D12 = False
motor_values.D21 = False
motor_values.D22 = True
motor_values.Shoot = True

# Convert the class instance to bytes
data_bytes = motor_values.ToBytes()

with serial.Serial('/dev/ttyACM0', 9600, timeout=5) as ser:
    while True:
        print("-----------------")

        print(data_bytes)
        ser.write(data_bytes)

        myBytes = ser.read(1)

        bufferBytes = ser.inWaiting()

        if bufferBytes:
            myBytes = myBytes + ser.read(bufferBytes)
        print(myBytes.decode("ascii"))

        time.sleep(1)
