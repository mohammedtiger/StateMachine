
#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <stdio.h>

/* state codes */
typedef enum state_codes{
    entry = 0,
    idle,
    startTrip,
    endTrip,
    errorHandler,

    /* the last entry is just for looping over the enum */
    STATE_LAST
}state_codes_t;

/* return codes */
typedef enum ret_codes{
    ok = 0,
    fail,
    ret_start_trip,
    ret_end_trip,
    repeat,

    /* the last entry is just for looping over the enum */
    RET_LAST
}ret_codes_t;

typedef struct transition{
    state_codes_t dst_state;
}transition_t;

ret_codes_t entry_state(void);
ret_codes_t idle_state(void);
ret_codes_t startTrip_state(void);
ret_codes_t endTrip_state(void);
ret_codes_t errorHandler_state(void);
state_codes_t lookup_transitions(state_codes_t state_codes, ret_codes_t ret_codes);



#endif /* STATE_MACHINE_H_ */
