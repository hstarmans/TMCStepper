# Python wrapper for the Arduino library
The following library is needed for Raspberry. [Airspayce](http://www.airspayce.com) is the official site
and can be used to retrieve the latest version.
```
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz 
tar zxvf bcm2835-1.xx.tar.gz
cd bcm2835-1.xx
./configure
make
sudo make check
sudo make install
```
Recursive clone, cleaner would be to use python module for pybind
```
git clone --recurse-submodules https://github.com/hstarmans/TMCStepper.git
```
Install cmake
```
sudo apt -y install cmake
```
Library can be compiled or installed using python.
```
python3 setup.py develop --user
```
More direct way of compling is
```
cmake -H. -Bbuild & make -C ./build
```
# Testing
The test pure.py in the folder test/pure.py should pass.
By changing the cmakelist file, C++ examples can be compiled. In specific, examples/Simple is modified for Firestarter board.
Test_connection complains about no power applied to board but it should result in power on to the motors.
This error seems to be a problem with the library.  
The library can be tested with libtest.py which is available in the test folder.


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
