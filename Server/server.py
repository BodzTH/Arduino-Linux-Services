import socket
import time
import sys
print("Argument 1:", sys.argv[1])
print("Argument 2:", sys.argv[2])
print("Argument 3:", sys.argv[3])
HOST = "127.0.1.2"
PORT = 65432
x=1;
print('iam in py')
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print(f"Server listening on {HOST}:{PORT}")
    conn, addr = s.accept()
    print('Connected by', addr)

    while x<4:
        # Get user input to send data
        print('iam about to take the input')
        print('took the input')   
        
        try:
            conn.sendall(sys.argv[x].encode())
            print('Sent:', sys.argv[x])      
            x=x+1     
        except Exception as e:
            print("Server error:", e)
            break
          # Optional delay between messages

    print("Closing connection")
    conn.close()
