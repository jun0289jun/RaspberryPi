import spidev
import time

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 1000000

def analog_read(channel):
    r = spi.xfer2([1, (0x08+channel)<<4, 0]) #spi.xfer2# analog_read 함수값을 읽어들임

    adc_out = ((r[1]&0x03)<<8) + r[2]
    return adc_out

while True:
    adc = analog_read(0) #channel
    voltage = adc*3.3/1023
    print("ADC = %d\t Voltage = %f" % (adc, voltage))
    time.sleep(0.5)
