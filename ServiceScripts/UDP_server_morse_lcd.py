import socket
import time
import sys

# Create a UDP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the address and port
server_address = ('127.0.1.1', 65432)  # Change this to your desired server address and port
server_socket.bind(server_address)
x=1
try:
	print("Waiting for a message...")
	# Receive data from the client and client's address
	data, address = server_socket.recvfrom(1024)  # Adjust the buffer size as needed
	print(f"Received {len(data)} bytes from {address}")
	print("Data:", data.decode())
	while True:
		# Sending a response back to the client
		sys.argv[x]
		#user_input=input("Enter your message: ")
		server_socket.sendto(sys.argv[x].encode(), address)        
		if(sys.argv[x]=="q"):
			print("Server stopped by the user.")
			break
		x=x+1

except KeyboardInterrupt:
    print("Server stopped by the user.")

finally:
    # Close the server socket
    server_socket.close()
