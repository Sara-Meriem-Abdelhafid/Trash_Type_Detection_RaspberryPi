import network 
import ubinascii
import socket
from time import sleep
#from picozero import pico_temp_sensor, pico_led
from machine import Pin


wlan = network.WLAN(network.STA_IF)# wirless lan network as a station STA_IF ,,,, AP_IF if we want it to be the acess point
wlan.active(True)

#print(wlan.scan()) #to see all ap adresses 
#mac = ubinascii.hexlify(network.WLAN().config('mac'),':').decode() #to print my devise mac adress 
#print('\n\n MAC', mac) 

ssid = 'MyNetwork'
password = 'abdelhafid2023A@abd'
wlan.connect(ssid, password)

html="""<!DOCTYPE html>
<html>
    <head><title>Raspberry Pico W Server</title></head>
    <body>
        <h1>Raspberry Pico W Server</h1>
        <p>%s</p>
    </body>
</html>
"""


led = Pin(0, Pin.OUT)



#wait for connect or fail
max_wait = 20
while max_wait > 0:
    if wlan.status() < 0 or wlan.status() >= 3:
        print("failed to connect, wlan.status() = ",wlan.status())
        break
    max_wait -= 1
    print("waiting for connection...")
    sleep(1)
    
#handle connection error
if wlan.status() != 3:
    raise RuntimeError('Network Connection Failed!')
else:
    print('Connected!')
    status= wlan.ifconfig()
    print('ip',status[0])
    print('status',status)
    
    
    
#open a tcp socket
addr= socket.getaddrinfo('0.0.0.0',80)[0][-1] 

s = socket.socket()
s.bind(addr)
s.listen(1)

print('listening on', addr)

while True:
    try:
        cl, addr = s.accept()
        print("client connected from ",addr)
        request = cl.recv(1024)
        print(request)
        
        request = str(request)
        led_on = request.find('/led/on')
        led_off = request.find('/led/off')
        print('led on = '+str(led_on))
        print('led off = '+str(led_off))
        
        stateis = "Led Unkown"
        
        if led_on == 6:
            print("led on")
            led.value(1)
            stateis = "Led is ON"
            
        
         if led_on == 6:
            print("led off")
            led.value(0)
            stateis = "Led is OFF"
        
        response = html % stateis
        cl.send('HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n')
        cl.send(response)
        cl.close()

    except OSError as e:
        cl.close()
        print('connection closed')     

    
