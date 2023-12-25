Creating a Service on Ubuntu with systemd
This guide outlines the steps to create a custom service on Ubuntu using systemd.

Prerequisites
Ubuntu OS (this guide assumes Ubuntu 18.04 or later)
Basic knowledge of bash scripting
Steps to Create a Service
Step 1: Prepare your script
Create a script (e.g., myservice.sh) that you want to run as a service.
Ensure the script has the necessary permissions to execute (chmod +x myservice.sh).
Step 2: Create the .service file
Open a text editor and create a new file named myservice.service.
Define the service configuration using the following template:
plaintext
Copy code
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
Replace:

Description: A descriptive name for your service.
After: Specify units your service depends on (e.g., network.target).
ExecStart: Path to your script.
Restart: Configure the service restart behavior.
User and Group: Set the user and group under which the service should run.
WantedBy: Set the target that wants to activate this unit (e.g., multi-user.target).
Step 3: Configure and Enable the Service
Move the .service file to /etc/systemd/system/ directory.
Run sudo systemctl daemon-reload to reload systemd.
Enable your service: sudo systemctl enable myservice.service.
Start your service: sudo systemctl start myservice.service.
Check the status: sudo systemctl status myservice.service.
Step 4: Troubleshooting
If your service fails to start, check logs: journalctl -xe.
Ensure your script runs independently outside the service context.
