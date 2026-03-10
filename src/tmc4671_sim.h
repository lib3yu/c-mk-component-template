#ifndef TMC4671_SIM_H_
#define TMC4671_SIM_H_

#include <stdint.h>
#include <stddef.h>

#define TMC4671_SIM_MAX_IC_COUNT 4

typedef struct lua_State lua_State;

void tmc4671_sim_set_lua_state(lua_State *L);

#endif
