from picozero import pico_led, LED

from time import sleep
'''led1 = LED(0) # Use GP13
led2 = LED(1) # Use GP13
led3 = LED(2) # Use GP13
led4 = LED(3) # Use GP13
switch = Switch(18) # Use GP18 Button on/off
'''

#pico_led.off()
#pico_led.on()
#sleep(1)
#pico_led.off()

while True:
    
     #if switch.is_closed: # Wires are connected
    pico_led.on()
    sleep(0.5) # Stay on for half a second
    pico_led.off()
    sleep(0.5) # Stay off for 2.5 seconds
    
    
    
    
    
    
    import network
import socket
from time import sleep
from picozero import pico_temp_sensor, pico_led
import machine

ssid = 'MyNetwork'
password = 'abdelhafid2023A@abd'




 
def connect():
    #Connect to WLAN
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while wlan.isconnected() == False:
        print('Waiting for connection...')
        sleep(1)        
    ip = wlan.ifconfig()[0]
    print(f'Connected on {ip}')
    return ip


def open_socket(ip):
    # Open a socket
    address = (ip, 80)
    print(f'Socket address is {address}')
    
    connection = socket.socket()
    connection.bind(address)
    connection.listen(1)
    print(connection)
    return connection

def webpage(temperature, state):
    #Template HTML
    html = f"""
        <!DOCTYPE html>
        <html>
            <body>
                <form action="./lighton">
                    <input type="submit" value="Light on" />
                </form>
                <form action="./lightoff">
                    <input type="submit" value="Light off" />
                </form>
                <p>LED is {state}</p>
                <p>Temperature is {temperature}</p>
            </body>
        </html> """
 
def serve(connection):
    #Start a web server
    state = 'OFF'
    pico_led.off()
    temperature = 0
    while True:
        client = connection.accept()[0]
        request = client.recv(1024)
        request = str(request)
        print(request)
        try:
            request = request.split()[1]
        except IndexError:
            pass
        if request == '/lighton?':
            pico_led.on()
            state = 'ON'
        elif request =='/lightoff?':
            pico_led.off()
            state = 'OFF'
        temperature = pico_temp_sensor.temp

        html = webpage(temperature, state)
        client.send(html)
        client.close()
try:
    ip = connect()
    connection = open_socket(ip)
    serve(connection)

except KeyboardInterrupt:
    machine.reset()