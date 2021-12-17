from socket import *
from pygame import mixer

serverSocket = socket(AF_INET, SOCK_DGRAM) #UDP socket
serverSocket.bind(('', 9324)) #Bind to "YEAH"
mixer.init()
mixer.music.load("C:\Users\Achinthya\Downloads\Koolaid Man.mp3")

while True:
    message = serverSocket.recvfrom(1024)

    if 'YEAH' in message[0]:
        print(message)
        mixer.music.play()