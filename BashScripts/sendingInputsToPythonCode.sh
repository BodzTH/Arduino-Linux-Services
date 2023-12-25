#!/bin/bash

# Your Python script filename
PYTHON_SCRIPT="your_python_script.py"

# Run the Python script
python3 "$PYTHON_SCRIPT" &

# Get the PID of the Python process
PYTHON_PID=$!

# Function to send input to the Python script
send_input() {
    input="$1"
    echo "$input"
    sleep 1  # Optional delay after sending input
}

# Example inputs to send
send_input "Hello, Python!"
send_input "How are you?"
send_input "q"  # To quit

# Wait for the Python process to finish
wait $PYTHON_PID
