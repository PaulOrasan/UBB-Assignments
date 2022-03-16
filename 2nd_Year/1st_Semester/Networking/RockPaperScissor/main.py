import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('193.231.20.3', 1276)
print ("Please enter\n"+ "0 - rock\n" + "1 - paper\n" + "2 - scissor\n")

def getInput():
    inp = ""
    while inp not in ["0", "1", "2"]:
        inp = input(">>> ")
    return inp

s.connect(server_address)


rev = -1
while rev not in ["0", "1"]:
    s.send(getInput().encode())
    rev = s.recv(1).decode("utf-8")
    if rev == "2":
        print ("Remiza")

print(rev)
if rev == "0":
    print("You win")
else:
    print("You lose")
