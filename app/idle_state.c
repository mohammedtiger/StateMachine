#include "state_machine.h"


int counter = 0;


ret_codes_t idle_state(void)
{
	counter ++;
	if(counter < 2)
	{
		printf("IDLE\n");
		return fail;
	}
	else
	{
		printf("IDLE\n");
		counter = 0;
		return ret_start_trip;

	}

}
