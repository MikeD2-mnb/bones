import time
import board
import busio
import os

os.system("config-pin P9.17 spi_cs")
os.system("config-pin P9.18 spi")
os.system("config-pin P9.21 spi")
os.system("config-pin P9.22 spi_sclk")

spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)
while not spi.try_lock():
    pass
spi.configure(baudrate=100000)


x=0
f = 0
while True:
    x +=1
    if x>255:
        x=0
    
    spi.write_readinto(bytes(x),f)
    print(x,f)
    time.sleep(0.01)
    
spi.unlock()