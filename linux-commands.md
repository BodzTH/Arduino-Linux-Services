### Linux Commands

#### Using Python for Serial Communication:
```bash
pip install pyserial
```

#### Identify the port to which the Arduino is connected:
```bash
ls /dev/tty*
```
Use the command before and after connecting the Arduino to see which new port appears.
If it doesn't appear use Arduino IDE and go to Tools --> port.

#### Reading Data from Serial Port using cat command
```bash
cat /dev/ttyS0
```

Replace /dev/ttyS0 with your Arduino's serial port.



