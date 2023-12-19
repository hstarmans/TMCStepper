from gpiozero import LED

test_pin = 27
led = LED(test_pin)

dct = {'clock': 21, 'mosi': 20, 'miso':19, 'motor_enable':17, 'spi_select':7}

for name, value in dct.items():
    print(f"Press enter to enabling pin {name}")
    input()
    led = LED(value)
    led.on()
    print(f"Press enter to disable pin {name}")
    input()
    led.off()

