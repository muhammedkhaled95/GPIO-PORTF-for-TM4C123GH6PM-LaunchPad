#include "gpio.h"

int main(void)
{
		uint32_t status;
		PORTF_init();
		
		
		while(1)
		{
			status = read_PORTF();
			switch(status)
			{
				case SW1:
					write_PORTF(RED);
					break;
				
				case SW2:
					write_PORTF(BLUE);
				  break;
				
				case SW1AND2:
					write_PORTF(GREEN);
					break;
				
				default:
					write_PORTF(0);
					break;
					
			}
		}
}
