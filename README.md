# bones
Beaglebone black / green
Hopefully this will hold working examples for Beaglebone
1) SPI interfaces - Most examples found on line are either incomplete or not working. While using these interfaces is easy in python, doing this in C is more obscure. Based on work by  Vinay Divakar, whwre the main.c program is missing an include directive. These libraries have been extended to cover both SPI0.0 and SPI1.0 interface 0.1 and 1.1 are available from the processor, but 0.1 the chip select line only goes to the SD card.
2) GPIO - the c examples included in the os using gpiod don't compile. I havent managed to find any working gpiod c code.  I've put a simple c lib together that uses the /sys/class/gpio.
3) SPIDEV DTBO - the device tree overlays for the SPI_DEV distributed with the latest IOT firmware for the beaglebones don't work. The older DTBO's still do, and the current ones can be edited to make them work - some of the pin register valuse are set incorrectly.
4) The BBB-.ods file contains a spreadsheet of the p9 pins, pin register offsets and the various mode functions. usefull for planing interface allocation
