import socket
import threading

def clientthread(conn):
    while True:
        data = conn.recv(1024)
        if not data:
            break
        print("From connected user: ",str(data.decode()))
        data = str(data).upper()
        print("sending: " + str(data))
        conn.send(data.encode())
    conn.close()

def Main():
    host = '127.0.0.1'
    port = 5000

    s = socket.socket()
    s.bind((host,port))
    s.listen(5)
    while True:
        c, addr = s.accept()
        print("Connection from: ",str(addr))
        t = threading.Thread(target=clientthread(c))
        t.daemon = False
        t.start()
        print("passed connection to thread: ",str(addr))
    s.close()

if __name__ == '__main__':
    Main()