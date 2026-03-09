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
#include "unity.h"
#include "queue.h"
#include "log.c/log.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>

/* Private define 0 ----------------------------------------------------------*/
/* Private macro 0 -----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private define 1 ----------------------------------------------------------*/
/* Private macro 1 -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;
/* Private function prototypes -----------------------------------------------*/
static void log_lock(bool lock, void *udata);
/* Private define 2 ----------------------------------------------------------*/
/* Private macro 2 -----------------------------------------------------------*/
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
    // Set up thread-safe logging with pthread mutex
    log_set_lock(log_lock, NULL);

    // Set log level (LOG_INFO shows info, warning, error, and fatal messages)
    log_set_level(LOG_INFO);

    // Enable quiet mode (set to false to see all log messages)
    log_set_quiet(false);

    // Optionally add file logging
    // FILE *fp = fopen("application.log", "a");
    // if (fp) {
    //     log_add_fp(fp, LOG_INFO);
    // }

    log_info("Log system initialized with thread-safe mutex");
    return 0;
}

/* Lua integration test ------------------------------------------------------*/
static int test_lua_integration(void)
{
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        log_error("Failed to create Lua state");
        return -1;
    }

    luaL_openlibs(L);

    const char *lua_code = "print('Hello from Lua 5.5!'); return 42";
    int ret = luaL_dostring(L, lua_code);

    if (ret != LUA_OK) {
        log_error("Lua error: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
        lua_close(L);
        return -1;
    }

    if (lua_isinteger(L, -1)) {
        int result = (int)lua_tointeger(L, -1);
        log_info("Lua returned: %d", result);
    }

    lua_close(L);
    return 0;
}
/* Public application code ---------------------------------------------------*/

/* Unity Test Setup / Teardown -----------------------------------------------*/
void setUp(void) {}
void tearDown(void) {}

/* Lua Unity tests -----------------------------------------------------------*/
void test_lua_state_creation(void)
{
    lua_State *L = luaL_newstate();
    TEST_ASSERT_NOT_NULL(L);
    lua_close(L);
}

void test_lua_dostring(void)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int ret = luaL_dostring(L, "return 1 + 1");
    TEST_ASSERT_EQUAL_INT(LUA_OK, ret);
    TEST_ASSERT_EQUAL_INT(2, (int)lua_tointeger(L, -1));
    lua_close(L);
}

/* Entry point ---------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    _log_init();

    log_info("Hello log.c\n");

    queue_t q;
    int ret = newqueue(&q, sizeof(int), 32);

    printf("Hello World!, %d\n\n", ret);

    /* Test Lua integration */
    printf("-----------------------\n");
    printf("---- Lua Testing ------\n");
    test_lua_integration();
    printf("\n");

    printf("-----------------------\n");
    printf("---- Unity Testing ----\n");

    /* Unity unit tests */
    UNITY_BEGIN();

    /* Test simple assertions */
    TEST_ASSERT_TRUE(1);
    TEST_ASSERT_FALSE(0);
    TEST_ASSERT_NULL(NULL);
    TEST_ASSERT_NOT_NULL((void *)1);

    /* Test integer equality */
    int a = 5;
    int b = 5;
    TEST_ASSERT_EQUAL_INT(a, b);
    TEST_ASSERT_EQUAL(10, 5 + 5);

    /* Test string equality */
    const char *str = "Hello";
    TEST_ASSERT_EQUAL_STRING("Hello", str);

    /* Lua tests */
    RUN_TEST(test_lua_state_creation);
    RUN_TEST(test_lua_dostring);

    return UNITY_END();
}


#ifdef __cplusplus
}
#endif /* __cplusplus */

