import serial

ser = serial.Serial('/dev/ttyACM0', 9600)  # Replace with your port and baud rate

# Assuming Arduino sends data in format: "temperature,humidity\n"
while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').strip()
        print(f'Received data: {data}')


