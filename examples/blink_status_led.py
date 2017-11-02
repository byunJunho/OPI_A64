#!/usr/bin/env python

import os
import sys

if not os.getegid() == 0:
    sys.exit('Script must be run as root')

from time import sleep
from OPi.gpio import gpio
from OPi.gpio import port

led = port.STATUS_LED

gpio.init()
gpio.setcfg(led, gpio.OUTPUT)

try:
    print ("Press CTRL+C to exit")
    while True:
        gpio.output(led, 1)
	print "led set 1 \r\n"
        sleep(1)
        gpio.output(led, 0)
	print "led set 0 \r\n"
        sleep(1)

except KeyboardInterrupt:
    gpio.output(led, 0)
	print ("Bye.")
