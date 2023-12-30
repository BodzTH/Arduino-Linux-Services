import socket
import time
import sys

# Create a UDP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the address and port
server_address = ('127.0.1.1', 65432)  # Change this to your desired server address and port
server_socket.bind(server_address)
size=0
sys.argv[1]
array={}
try:
    while size<5:
        if(size>0):        
            print("Waiting for a message...")
            # Receive data from the client and client's address
            data, address = server_socket.recvfrom(1024)  # Adjust the buffer size as needed
            print(f"Received {len(data)} bytes from {address}")
            print("Data:", data.decode())
            array.append(data.decode())

        # Sending a response back to the client
        #user_input=input("Enter your message: ")
        server_socket.sendto(sys.argv[1].encode(), address)        


except KeyboardInterrupt:
    print("Server stopped by the user.")

finally:
    # Close the server socket
    server_socket.close()
    for x in array:
      print(x)
