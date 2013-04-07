/*!
 * \file main.c
 * \author Max Gröning (mail@max-g.net)
 * \date April, 2013
 * \brief Demonstration of the Stepper Booster Library
 */
#include <msp430.h>
#include "stepper/stepper.h"

int main(void) {
	/* Initialize */
	WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

	P1DIR = 0x0;  // Configure all I/Os as inputs
	P2DIR = 0x0;  //
	P1OUT = 0x0;
	P2OUT = 0x0;

	stepper_init();  // Initialize stepper booster

	stepper_full_step();
//	stepper_half_step();
//	stepper_quarter_step();
//	stepper_8_microstep();
//	stepper_16_microstep();
//	stepper_32_microstep();

	stepper_no_sleep();
	stepper_enable();

	unsigned i = 0;
	while(1) {
		/* Different step sizes */
		stepper_full_step();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		stepper_half_step();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		stepper_quarter_step();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		stepper_8_microstep();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		stepper_16_microstep();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		stepper_32_microstep();
		for (i = 1000; i > 0; --i) {
			stepper_step();
			__delay_cycles(10000);
		}
		/* Different speeds and directions */
		stepper_full_step();
		for (i = 500; i > 0; --i) {
			stepper_step();
			__delay_cycles(5000);
		}
		stepper_dir_x();
		for (i = 500; i > 0; --i) {
			stepper_step();
			__delay_cycles(4000);
		}
		stepper_dir_x();
		for (i = 500; i > 0; --i) {
			stepper_step();
			__delay_cycles(3000);
		}
		stepper_dir_x();
		for (i = 500; i > 0; --i) {
			stepper_step();
			__delay_cycles(2000);
		}
		/* Turning with delays */
		stepper_full_step();
		stepper_dir_0();
		__delay_cycles(1000000);
		for (i = 100; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		__delay_cycles(1000000);
		stepper_dir_1();
		for (i = 25; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		__delay_cycles(1000000);
		stepper_dir_0();
		for (i = 50; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		__delay_cycles(1000000);
		stepper_dir_1();
		for (i = 25; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		__delay_cycles(1000000);
		/* Turning without delays */
		stepper_full_step();
		stepper_dir_0();
		for (i = 100; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		stepper_dir_1();
		for (i = 25; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		stepper_dir_0();
		for (i = 50; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
		stepper_dir_1();
		for (i = 25; i > 0; --i) {
			stepper_step();
			__delay_cycles(2500);
		}
	}
}

#pragma vector = ADC10_VECTOR, COMPARATORA_VECTOR, NMI_VECTOR, \
		PORT1_VECTOR, PORT2_VECTOR, TIMER0_A0_VECTOR, TIMER0_A1_VECTOR, \
		USI_VECTOR, WDT_VECTOR
__interrupt void ISR_trap(void) {
	// Causing an access violation which will result in a PUC reset
	WDTCTL = 0;
}
