/*!
 * \file stepper.c
 * \author Max Gröning (mail@max-g.net)
 * \date April, 2013
 * \brief Stepper Booster Library
 */

#include "stepper.h"

void stepper_init(void) {
	/*
	 * Sets up the Stepper Booster in Indexer Mode
	 */
	STEP_DIR |= STEP_PIN;  // Output
	STEP_OUT &= ~STEP_PIN;  // Low

	DIR_DIR |= DIR_PIN;  // Output
	DIR_OUT &= ~DIR_PIN;  // Low

	CONFIG_DIR |= CONFIG_PIN;  // Output
	CONFIG_OUT |= CONFIG_PIN;  // High, Indexer Mode

	M0_DIR |= M0_PIN;  // Output
	M0_OUT &= ~M0_PIN;  // Low

	M1_DIR |= M1_PIN;  // Output
	M1_OUT &= ~M1_PIN;  // Low

	nENBL_DIR |= nENBL_PIN;  // Output
	nENBL_OUT |= nENBL_PIN;  // High, stepper outputs disabled

	nSLEEP_DIR |= nSLEEP_PIN;  // Output
	nSLEEP_OUT &= ~nSLEEP_PIN;  // Low, stepper disabled/low-power sleep mode
	nSLEEP_SEL &= ~nSLEEP_PIN;   // Disable function select
	nSLEEP_SEL2 &= ~nSLEEP_PIN;  //

	nFAULT_DIR &= ~nFAULT_PIN;  // Input
	nFAULT_OUT |= nFAULT_PIN;  // Pullup
	nFAULT_SEL &= nFAULT_PIN;   // Disable function select
	nFAULT_SEL2 &= nFAULT_PIN;  //
	nFAULT_REN |= nFAULT_PIN;  // Enable Pullup/Pulldown resistor
}

void stepper_full_step(void) {
	/*
	 * Sets the Stepper Booster to full step mode (2-phase excitation)
	 */
	M0_DIR |= M0_PIN;  // Output
	M0_OUT &= ~M0_PIN;  // Low

	M1_DIR |= M1_PIN;  // Output
	M1_OUT &= ~M1_PIN;  // Low
}

void stepper_half_step(void) {
	/*
	 * Sets the Stepper Booster to 1/2 step mode (1-2 phase excitation)
	 */
	M0_DIR |= M0_PIN;  // Output
	M0_OUT |= M0_PIN;  // High

	M1_DIR |= M1_PIN;  // Output
	M1_OUT &= ~M1_PIN;  // Low
}

void stepper_quarter_step(void) {
	/*
	 * Sets the Stepper Booster to 1/4 step mode (W1-2 phase excitation)
	 */
	M0_DIR &= ~M0_PIN;  // Input = Z

	M1_DIR |= M1_PIN;  // Output
	M1_OUT &= ~M1_PIN;  // Low
}

void stepper_8_microstep(void) {
	/*
	 * Sets the Stepper Booster to 8 microsteps per step mode
	 */
	M0_DIR |= M0_PIN;  // Output
	M0_OUT &= ~M0_PIN;  // Low

	M1_DIR |= M1_PIN;  // Output
	M1_OUT |= M1_PIN;  // High
}

void stepper_16_microstep(void) {
	/*
	 * Sets the Stepper Booster to 16 microsteps per step mode
	 */
	M0_DIR |= M0_PIN;  // Output
	M0_OUT |= M0_PIN;  // High

	M1_DIR |= M1_PIN;  // Output
	M1_OUT |= M1_PIN;  // High
}

void stepper_32_microstep(void) {
	/*
	 * Sets the Stepper Booster to 32 microsteps per step mode
	 */
	M0_DIR &= ~M0_PIN;  // Input = Z

	M1_DIR |= M1_PIN;  // Output
	M1_OUT |= M1_PIN;  // High
}

void stepper_step(void) {
	/*
	 * Creates a step impulse
	 */
	STEP_OUT |= STEP_PIN;
	__delay_cycles(32);  // Wait ~2 µs @ 16 MHz
	STEP_OUT &= ~STEP_PIN;
	__delay_cycles(32);  // Wait ~2 µs @ 16 MHz
}

void stepper_dir_0() {
	/*
	 * Sets direction 0
	 */
	DIR_OUT &= ~DIR_PIN;
	__delay_cycles(4);  // ~250 ns @ 16 MHz
}
void stepper_dir_1() {
	/*
	 * Sets direction 1
	 */
	DIR_OUT |= DIR_PIN;
	__delay_cycles(4);  // ~250 ns @ 16 MHz
}
void stepper_dir_x() {
	/*
	 * Changes (toggles) direction
	 */
	DIR_OUT ^= DIR_PIN;
	__delay_cycles(4);  // ~250 ns @ 16 MHz
}

void stepper_sleep(void) {
	/*
	 * Enters low-power sleep
	 */
	nSLEEP_OUT &= ~nSLEEP_PIN;
}
void stepper_no_sleep(void) {
	/*
	 * Wakes up stepper booster
	 */
	nSLEEP_OUT |= nSLEEP_PIN;
	__delay_cycles(16000);  // Wait ~1 ms @ 16 MHz
}

void stepper_enable(void) {
	/*
	 * Enables outputs
	 */
	nENBL_OUT &= ~nENBL_PIN;
}
void stepper_disable(void) {
	/*
	 * Disables outputs
	 */
	nENBL_OUT |= nENBL_PIN;
}
