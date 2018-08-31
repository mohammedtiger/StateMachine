#include "state_machine.h"


/* transitions lookup table */
state_codes_t state_transitions[STATE_LAST][RET_LAST] = {
						/* ok, 	fail	, ret_start_trip, ret_end_trip, repeat */
    /*entry*/       	{idle,  errorHandler, errorHandler, errorHandler, entry},
    /*idle*/        	{idle,  errorHandler, startTrip,     endTrip,       idle},          /* ok, fail, ret_start_trip, ret_end_trip, repeat */
    /*startTrip*/   	{idle,  entry, startTrip,     endTrip,       startTrip},     /* ok, fail, ret_start_trip, ret_end_trip, repeat */
    /*endTrip*/     	{idle,  errorHandler, errorHandler, endTrip,       endTrip},        /* ok, fail, ret_start_trip, ret_end_trip, repeat */
    /*errorHandler*/    {idle,  errorHandler, errorHandler, errorHandler,  errorHandler},   /* ok, fail, ret_start_trip, ret_end_trip, repeat */
};


state_codes_t lookup_transitions(state_codes_t state_codes, ret_codes_t ret_codes)
{
    switch(state_transitions[state_codes][ret_codes]){
        case    entry:
            state_codes = entry;
            break;
        case    idle:
            state_codes = idle;
            break;
        case    startTrip:
            state_codes = startTrip;
            break;
        case    endTrip:
            state_codes = endTrip;
            break;
        case    errorHandler:
            state_codes = errorHandler;
            break;
        default:
            break;
    }

    return state_codes;
}
