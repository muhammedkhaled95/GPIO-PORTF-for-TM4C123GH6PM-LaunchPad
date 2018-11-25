#include "gpio.h"


void PORTF_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0X00000020; /*enable clock source for PORTF*/
	/*
	  The General- Purpose Input/Output Peripheral Ready (PRGPIO) register is used to monitor and indicate
    whether the selected GPIO Port is ready or not. Starting from bit 0 (R0) to bit 5 (R5), each
    bit is associated with a GPIO Port: R0, Port A; R1, Port B, . . . R5, Port F. if the selected
    port is ready, the corresponding bit is set to 1.
	 */
	while((SYSCTL_PRGPIO_R & 0X00000020) == 0){};
		
	/*
	  These two registers, GPIO Lock Register (GPIOLOCK) and GPIO Commit Register (GPIOCR), are used to
    provide commit controls to each bit for other four registers.
    • GPIO Lock Register (GPIOLOCK): Control writes access to the GPIOCR register. If
    the GPIOLOCK is unlocked (writing 0x4C4F434B to GPIOLOCK), the contents on
    GPIOCR can be modified by writing. Otherwise if this register is locked (writing any other
    number to GPIOLOCK), any writing to the GPIOCR is ignored and its contents cannot be changed.
					---------------------------------------------------------------
    • GPIO Commit Register (GPIOCR): Control (enable or disable) each bit on the other 4
    registers: GPIOAFSEL, GPIOPUR, GPIOPDR and GPIODEN. The value of the GPIOCR
    register determines which bits of those four registers are committed when a write to these registers is performed.
    • If a bit in the GPIOCR=0, the data being written to the corresponding bit in those registers
    cannot be committed or disabled and retains its previous value.
    • If a bit in the GPIOCR= 1, the data being written to the corresponding bit of those registers
    is committed or enabled to the register and reflects the new value.
    The contents of the GPIOCR register can only be modified if the status in the GPIOLOCK register is unlocked.
	*/
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R = 0X1F;
	
	GPIO_PORTF_DIR_R  |= 0X0000000E; /*pf0, and pf4 as Input ... pf1, pf2, and pf3 as Outptut*/
	GPIO_PORTF_PUR_R  |= 0X00000011; /*internal pull up enabled for pf0 and pf4 for sw0 and sw1*/
	GPIO_PORTF_DEN_R   = 0X0000001F; /*enable digital pins for all PORTF pins*/
}


uint32_t read_PORTF(void)
{
	return (GPIO_PORTF_DATA_R & 0X11); 
}

void write_PORTF(uint32_t data)
{
	GPIO_PORTF_DATA_R = data;
}
