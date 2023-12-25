# Creating a Service on Ubuntu with systemd

This guide outlines the steps to create a custom service on Ubuntu using systemd.

## Prerequisites

- Ubuntu OS (this guide assumes Ubuntu 18.04 or later)
- Basic knowledge of bash scripting

## Steps to Create a Service

### Step 1: Prepare your script

1. Create a script (e.g., `wlecome_service.sh`) that you want to run as a service.
2. Ensure the script has the necessary permissions to execute (`chmod +x myservice.sh`).

### Step 2: Create the `.service` file

1. Open a text editor and create a new file named `myservice.service`.
2. Define the service configuration using the following template:
```
[Unit]
Description=Run Once After Boot
After=multi-user.target

[Service]
Type=oneshot
ExecStart=/path/to/your/script.sh

[Install]
WantedBy=multi-user.target
```


Replace:
- `Description`: A descriptive name for your service.
- `After`: Specify units your service depends on (e.g., `network.target`).
- `ExecStart`: Path to your script.
- `WantedBy`: Set the target that wants to activate this unit (e.g., `multi-user.target`).

### Step 3: Configure and Enable the Service

1. Move the `.service` file to `/etc/systemd/system/` directory.
2. Run `sudo systemctl daemon-reload` to reload systemd.
3. Enable your service: `sudo systemctl enable myservice.service`.
4. Start your service: `sudo systemctl start myservice.service`.
5. Check the status: `sudo systemctl status myservice.service`.

### Step 4: Troubleshooting

- If your service fails to start, check logs: `journalctl -xe`.
- Ensure your script runs independently outside the service context.

  [explanition video](https://youtu.be/2gyKkgguyxE?si=xlyiLLJa7f_7iJ3S)
