/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : source for main
  ******************************************************************************
  * @attention
  *
  * Copyright (c) lib3yu(neon).
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
***/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "log.c/log.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "tmc4671_sim.h"
#include "TMC4671.h"
#include "unity.h"
/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>

/* External test functions */
extern void test_ic0_register_read_write(void);
extern void test_ic1_register_read_write(void);
extern void test_ic0_target_velocity(void);
extern void test_ic1_target_velocity(void);
extern void test_ic0_target_position(void);
extern void test_ic1_target_position(void);
extern void test_two_ic_isolation(void);

/* Private variables ---------------------------------------------------------*/
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Private function prototypes -----------------------------------------------*/
static void log_lock(bool lock, void *udata);

/* Private function code -----------------------------------------------------*/
static void log_lock(bool lock, void *udata)
{
    (void)udata;
    if (lock) {
        pthread_mutex_lock(&log_mutex);
    } else {
        pthread_mutex_unlock(&log_mutex);
    }
}

static int _log_init(void)
{
    log_set_lock(log_lock, NULL);
    log_set_level(LOG_INFO);
    log_set_quiet(false);
    log_info("Log system initialized");
    return 0;
}

/* Entry point */
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    _log_init();
    log_info("TMC4671 Lua SPI Simulator");

    lua_State *L = luaL_newstate();
    if (L == NULL) {
        log_error("Failed to create Lua state");
        return 1;
    }

    luaL_openlibs(L);

    if (luaL_dofile(L, "lua/tmc4671_sim_spi.lua") != LUA_OK) {
        log_error("Failed to load Lua script: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
        lua_close(L);
        return 1;
    }

    tmc4671_sim_set_lua_state(L);

    log_info("Running tests...");

    UNITY_BEGIN();
    RUN_TEST(test_ic0_register_read_write);
    RUN_TEST(test_ic1_register_read_write);
    RUN_TEST(test_ic0_target_velocity);
    RUN_TEST(test_ic1_target_velocity);
    RUN_TEST(test_ic0_target_position);
    RUN_TEST(test_ic1_target_position);
    RUN_TEST(test_two_ic_isolation);
    int result = UNITY_END();

    lua_close(L);

    return result;
}


#ifdef __cplusplus
}
#endif /* __cplusplus */
