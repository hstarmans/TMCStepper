/**
 * Author Teemu Mäntykallio, Henri Starmans
 * Initializes the library 
 * Stepper motors can not be directly pulsed from FPGA
 * In your case drivers are also connected in a ring!
 */
#include <TMCStepper.h>

#define CS_PIN           RPI_V2_GPIO_P1_26  // Chip select                         GPIO7
#define SW_MOSI          RPI_V2_GPIO_P1_38  // Software Master Out Slave In (MOSI) GPIO20
#define SW_MISO          RPI_V2_GPIO_P1_35  // Software Master In Slave Out (MISO) GPIO19
#define SW_SCK           RPI_V2_GPIO_P1_40  // Software Slave Clock (SCK)          GPIO21
#define EN_PIN           RPI_V2_GPIO_P1_11  // Enable pin motor gpio 17

#define R_SENSE 0.11f // Match to your driver
                      // SilentStepStick series use 0.11
                      // UltiMachine Einsy and Archim2 boards use 0.2
                      // Panucatt BSD2660 uses 0.1
                      // Watterott TMC5160 uses 0.075


// chain_length is defined in TMCStepper class and has been modified
// by changing original files, note that chain lenght is also changed by passing the one with the largest index
int8_t x_index=0;
int8_t y_index=1;
int8_t z_index=2;
TMC2130Stepper xdriver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK, z_index); // Software SPI
//int8_t xdriver.chain_length = 3;

int main() {
  bcm2835_init();
  //pinMode(10, OUTPUT);
  //pinMode(STEP_PIN, OUTPUT);
  //pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);      // Enable driver in hardware

                                  // Enable one according to your setup
  //xdriver.defaults();                    // SPI drivers
//SERIAL_PORT.begin(115200);      // HW UART drivers
//driver.beginSerial(115200);     // SW UART drivers

   xdriver.begin();                 //  SPI: Init CS pins and possible SW SPI pins
                                  // UART: Init SW UART (if selected) with default 115200 baudrate
  xdriver.toff(5);                 // Enables driver in software
  xdriver.rms_current(600);        // Set motor RMS current
  xdriver.microsteps(16);          // Set microsteps to 1/16th

  xdriver.en_pwm_mode(true);       // Toggle stealthChop on TMC2130/2160/5130/5160
//driver.en_spreadCycle(false);   // Toggle spreadCycle on TMC2208/2209/2224
//   xdriver.pwm_autoscale(true);     // Needed for stealthChop
  return 0;
}

// bool shaft = false;

// void loop() {
//   // Run 5000 steps and switch direction in software
//   //   for (uint16_t i = 5000; i>0; i--) {
//   //     digitalWrite(STEP_PIN, HIGH);
//   //     delayMicroseconds(160);
//   //     digitalWrite(STEP_PIN, LOW);
//   //     delayMicroseconds(160);
//   //   }
//   shaft = !shaft;
//   xdriver.shaft(shaft);
// }
