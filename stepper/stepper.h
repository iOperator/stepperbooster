/*!
 * \file stepper.h
 * \author Max Gröning (mail@max-g.net)
 * \date April, 2013
 * \brief Stepper Booster Library Header
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include <msp430.h>

#define STEP_OUT P2OUT
#define STEP_DIR P2DIR
#define STEP_PIN BIT0

#define DIR_OUT P2OUT
#define DIR_DIR P2DIR
#define DIR_PIN BIT1

#define CONFIG_OUT P2OUT
#define CONFIG_DIR P2DIR
#define CONFIG_PIN BIT5

#define M0_OUT P2OUT
#define M0_DIR P2DIR
#define M0_PIN BIT3

#define M1_OUT P2OUT
#define M1_DIR P2DIR
#define M1_PIN BIT4

#define nENBL_OUT  P2OUT
#define nENBL_DIR  P2DIR
#define nENBL_SEL  P2SEL
#define nENBL_SEL2 P2SEL2
#define nENBL_PIN  BIT2

#define nSLEEP_OUT  P2OUT
#define nSLEEP_DIR  P2DIR
#define nSLEEP_SEL  P2SEL
#define nSLEEP_SEL2 P2SEL2
#define nSLEEP_PIN  BIT6

#define nFAULT_IN   P2IN
#define nFAULT_OUT  P2OUT
#define nFAULT_DIR  P2DIR
#define nFAULT_IFG  P2IFG
#define nFAULT_IES  P2IES
#define nFAULT_IE   P2IE
#define nFAULT_SEL  P2SEL
#define nFAULT_SEL2 P2SEL2
#define nFAULT_REN  P2REN
#define nFAULT_PIN  BIT7


void stepper_init(void);  // Sets up the Stepper Booster in Indexer Mode

void stepper_full_step(void);  // Sets the Stepper Booster to full step mode (2-phase excitation)
void stepper_half_step(void);  // Sets the Stepper Booster to 1/2 step mode (1-2 phase excitation)
void stepper_quarter_step(void);  // Sets the Stepper Booster to 1/4 step mode (W1-2 phase excitation)
void stepper_8_microstep(void);  // Sets the Stepper Booster to 8 microsteps per step mode
void stepper_16_microstep(void);  // Sets the Stepper Booster to 16 microsteps per step mode
void stepper_32_microstep(void);  // Sets the Stepper Booster to 32 microsteps per step mode

void stepper_step(void);  // Creates a step impulse

void stepper_dir_0();  // Sets direction 0
void stepper_dir_1();  // Sets direction 1
void stepper_dir_x();  // Changes (toggles) direction

void stepper_sleep(void);
void stepper_no_sleep(void);

void stepper_enable(void);
void stepper_disable(void);


#endif /* STEPPER_H_ */
