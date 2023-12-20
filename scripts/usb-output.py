import socket

# Define the server's IP address and port
server_ip = "0.0.0.0"  # Listen on all available interfaces
server_port = 5008  # Use the same port as configured in the ESP32-CAM code

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the IP address and port
server_socket.bind((server_ip, server_port))

# Listen for incoming connections (max backlog of connections set to 5)
server_socket.listen(5)

print(f"Listening for incoming connections on port {server_port}...")

while True:
    # Accept incoming connection
    client_socket, client_address = server_socket.accept()

    print(f"Connection from {client_address} has been established.")

    # Receive data from the client
    received_data = client_socket.recv(1024).decode("utf-8")
    print(f"Received data: {received_data}")

    # Optionally, you can add your own logic here to process the received data

    # Close the connection with the client
    client_socket.close()
