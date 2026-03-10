#include "tmc4671_sim.h"
#include "lua.h"
#include "lauxlib.h"
#include <stdbool.h>
#include <stddef.h>

static lua_State *g_lua_state = NULL;

void tmc4671_sim_set_lua_state(lua_State *L)
{
    g_lua_state = L;
}

void tmc4671_readWriteSPI(uint16_t icID, uint8_t *data, size_t dataLength)
{
    (void)dataLength;

    if (icID >= TMC4671_SIM_MAX_IC_COUNT || g_lua_state == NULL || data == NULL) {
        return;
    }

    lua_State *L = g_lua_state;

    uint8_t address = data[0] & 0x7F;
    bool is_write = (data[0] & 0x80) != 0;

    lua_getglobal(L, "tmc4671_sim_spi");
    if (!lua_isfunction(L, -1)) {
        lua_pop(L, 1);
        data[1] = data[2] = data[3] = data[4] = 0;
        return;
    }

    lua_pushinteger(L, icID);
    lua_pushboolean(L, is_write);
    lua_pushinteger(L, address);

    if (is_write) {
        uint32_t value = ((uint32_t)data[1] << 24) |
                         ((uint32_t)data[2] << 16) |
                         ((uint32_t)data[3] << 8)  |
                         ((uint32_t)data[4]);
        lua_pushinteger(L, (lua_Integer)(int32_t)value);
    } else {
        lua_pushnil(L);
    }

    if (lua_pcall(L, 4, 1, 0) != LUA_OK) {
        lua_pop(L, 1);
        data[1] = data[2] = data[3] = data[4] = 0;
        return;
    }

    if (is_write) {
        lua_pop(L, 1);
    } else {
        if (lua_isinteger(L, -1)) {
            uint32_t value = (uint32_t)lua_tointeger(L, -1);
            data[1] = (value >> 24) & 0xFF;
            data[2] = (value >> 16) & 0xFF;
            data[3] = (value >> 8)  & 0xFF;
            data[4] = value & 0xFF;
        }
        lua_pop(L, 1);
    }
}
