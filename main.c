
#include "app/state_machine.h"

#define ENTRY_STATE entry

/*========================================================================
 * 								  Function
 *=======================================================================*/

static ret_codes_t (* const state[])(void) = { entry_state, idle_state, startTrip_state, endTrip_state , errorHandler_state};

/*=========================================================================
 * 									Main
 *=======================================================================*/

int main(void)
{
	state_codes_t cur_state = ENTRY_STATE;
	ret_codes_t rc;
	ret_codes_t (* state_fun)(void);

	// Loop forever, processing the osn-screen animation.  All other work is
	// done in the interrupt handlers.

	while(1)
	{

		state_fun = state[cur_state];
		rc = state_fun();
		cur_state = lookup_transitions(cur_state, rc);


	}
	return 0 ;
}






