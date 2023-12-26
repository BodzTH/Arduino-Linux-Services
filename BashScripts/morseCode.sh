#!/bin/bash

# Check if two parameters are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <parameter1> <parameter2>"
    exit 1
fi

# Assign parameters to variables
PARAM1="$1"
PARAM2="$2"

# Your Python script filename
PYTHON_SCRIPT="your_python_script.py"

# Run the Python script
python3 "$PYTHON_SCRIPT" &

# Get the PID of the Python process
PYTHON_PID=$!

# Pass parameters as initial inputs to the Python script
echo "$PARAM1" >&"${PYTHON_PID}Input"
echo "$PARAM2" >&"${PYTHON_PID}Input"

# End the connection by sending 'q'
echo "q" >&"${PYTHON_PID}Input"

# Wait for the Python process to finish
wait $PYTHON_PID
