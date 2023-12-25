# Creating a Service on Ubuntu with systemd

This guide outlines the steps to create a custom service on Ubuntu using systemd.

## Prerequisites

- Ubuntu OS (this guide assumes Ubuntu 18.04 or later)
- Basic knowledge of bash scripting

## Steps to Create a Service

### Step 1: Prepare your script

1. Create a script (e.g., `myservice.sh`) that you want to run as a service.
2. Ensure the script has the necessary permissions to execute (`chmod +x myservice.sh`).

### Step 2: Create the `.service` file

1. Open a text editor and create a new file named `myservice.service`.
2. Define the service configuration using the following template:

[Unit]
Description=My Custom Service
After=network.target

[Service]
Type=simple
ExecStart=/path/to/your/script/myservice.sh
Restart=always
User=your_username
Group=your_groupname

[Install]
WantedBy=multi-user.target
