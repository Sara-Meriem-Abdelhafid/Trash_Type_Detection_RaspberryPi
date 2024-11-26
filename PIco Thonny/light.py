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
 