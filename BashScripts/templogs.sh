#!/bin/bash

connect_to_wifi() {
    echo "Not connected to the desired Wi-Fi network. Trying to connect..."
    nmcli device wifi connect "$desired_ssid"
    
}

desired_ssid="ESP01S"
ssid=$(iwgetid -r)
counter=1
num_logs=5
if [ "$ssid" = "$desired_ssid" ]; then
    : # Do nothing
else
    connect_to_wifi
fi

if [ "$ssid" = "$desired_ssid" ]; then
    echo "Connected to the desired Wi-Fi network."
    echo "Number of logs : $num_logs"
    for i in $(seq 1 $num_logs)
    do
        response=$(echo '1' | nc -u -w5 192.168.0.109 5009 & sleep 1)
        echo "$response - $(date) " >> /home/bodz/arduino_services/temphum.log
        echo "Log Saved $counter"
        counter=$((counter+1))
    done
else
    echo "Not connected to the desired Wi-Fi network. Skipping log generation."
fi
