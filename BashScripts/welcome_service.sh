#!/bin/bash

# Define the character to send
char_to_send="A"

# Define the serial port your Arduino is connected to
serial_port="/dev/ttyUSB0"  # Replace with your Arduino's port (e.g., ttyUSB0, ttyACM0)

# Send the character using echo
echo -n "$char_to_send" > "$serial_port"
