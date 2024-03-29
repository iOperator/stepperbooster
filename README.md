Dual Bridge Stepper BoosterPack
===============================

Library for the MSP430 LaunchPad Dual Bridge Stepper Booster

Max Gröning
2013/02

This BoosterPack utilizes a Texas Instruments DRV8834 (2.2A Low Voltage Stepper w/ 32-step Indexer or Dual Brushed DC Motor Driver) and was mainly designed as an expansion to the MSP430 LaunchPad ecosystem.
As indicated by the used IC above it can drive one stepper or two brushed DC motors. Four LEDs at the edge of the PCB give an overview of the 'enable', 'step', 'direction' and 'fault' stati.

Demo video: https://vimeo.com/63528798

Used LaunchPad Pins
-------------------

<pre>
VCC              GND
x             !SLEEP
x             !FAULT
x                  x
x                  x
x                  x
x                  x
STEP          CONFIG
DIR               M1
!ENBL             M0

x = N/C
</pre>
