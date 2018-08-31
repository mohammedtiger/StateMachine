#include "state_machine.h"

ret_codes_t startTrip_state(void)
{
	char a = 0;
	char enter = 0;
	scanf("%c" , &a);
	scanf("%c" , &enter);

	if(a == '0')
	{
		printf("START\n");
		return fail;
	}
	printf("START\n");
	return ok;
}
