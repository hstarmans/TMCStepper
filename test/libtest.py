import unittest
import steppers
from gpiozero import MCP3008


class MotorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        # load linked motors
        cls.motors = [steppers.TMC2130(link_index=i) for i in range(1, 4)]
        steppers.bcm2835_init()

    def test_simple(self):
        ''' write to all the motors
        '''
        # init bcm2835
        steppers.bcm2835_init()
        for motor in self.motors:
            motor.begin()
            motor.toff(5)
            motor.rms_current(600)
            motor.microsteps(16)
            motor.en_pwm_mode(True)
        # close bcm2835
        steppers.bcm2835_close()


if __name__ == '__main__':
    unittest.main()
