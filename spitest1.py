import spidev
import os
import time
try:
    os.system("config-pin P9.17 spi_cs")
    os.system("config-pin P9.18 spi")
    os.system("config-pin P9.21 spi")
    os.system("config-pin P9.22 spi_sclk")

except Exception as e:
    print(e)

spi_1 = spidev.SpiDev()
spi_1.open(0,0)
spi_1.max_speed_hz = 1000000
spi_1.mode = 0

x=0
f = 0
while True:
    x +=1
    if x>255:
        x=0
    
    f = spi_1.xfer([x,0xff])
    print(x,f)
    time.sleep(0.01)