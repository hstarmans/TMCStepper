# Micropython wrapper for the TMStepper library

TMCStepper library for ESP32 and micropython.
Compiled using the instructions on [Micropython](https://docs.micropython.org/en/latest/develop/extendingmicropython.html).
```
make USER_C_MODULES=enter_correct_path_here/TMCStepper/micropython.cmake
```
Library compiles and is tested. Please note that the drives can enter a failure mode, in which they no longer work.
Only a single function can be called which configures the motors.
This is done using the following commands.  
```python
import steppers
steppers.init()
```

# Documentation Original

Arduino library for Trinamic TMC stepper motor drivers.

Supported TMC drivers:
* [TMC2130][2130]
* [TMC2160][2160]
* [TMC2208][2208]
* [TMC2209][2209]
* [TMC2224][2224]
* [TMC2660][2660]
* [TMC5130][5130]
* [TMC5160][5160]
* [TMC5161][5161]

[2130]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2130_stepper.html
[2160]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2160_stepper.html
[2208]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2208_stepper.html
[2209]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2209_stepper.html
[2224]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2224_stepper.html
[2660]: https://teemuatlut.github.io/TMCStepper/class_t_m_c2660_stepper.html
[5130]: https://teemuatlut.github.io/TMCStepper/class_t_m_c5130_stepper.html
[5160]: https://teemuatlut.github.io/TMCStepper/class_t_m_c5160_stepper.html
[5161]: https://teemuatlut.github.io/TMCStepper/class_t_m_c5161_stepper.html

[New Doxygen documentation](https://teemuatlut.github.io/TMCStepper/index.html)

---

The TMCStepper library is and always will be free to use.
This project started for me as a personal test to see if I could do it. Over the years it has gained some popularity as more and more hobbyists are looking into advanced stepper motor drivers. More users also comes with more unique setups.
This donation option will allow me to purchase the hardware that I can use for testing, validation and supporting you.

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=KFRSQ3KUUPKWS&currency_code=EUR&source=url)

- [x] ESP-PROG for debugging ESP32 support
- [ ] SKR Pro V1.2 for testing STM32 based boards

