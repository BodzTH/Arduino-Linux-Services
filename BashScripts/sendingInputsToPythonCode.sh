#!/bin/bash

# Your Python script filename
PYTHON_SCRIPT="your_python_script.py"

# Run the Python script
python3 "$PYTHON_SCRIPT" &

# Get the PID of the Python process
PYTHON_PID=$!

# Function to send input to the Python script
send_input() {
    read -p "Enter message to send ('q' to quit): " user_input
    echo "$user_input"
    sleep 1  # Optional delay after sending input
}

# Loop to continuously get user input until 'q' is entered
while true; do
    input=$(send_input)

    # Pass user input to the Python script
    echo "$input" >&"${PYTHON_PID}Input"
    if [[ "$input" == "q" ]]; then
        break
    fi
done

# Wait for the Python process to finish
wait $PYTHON_PID
