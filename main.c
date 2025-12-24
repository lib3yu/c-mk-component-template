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
#include "queue.h"
#include "log.c/log.h"
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
/* Public application code ---------------------------------------------------*/

/* Entry point ---------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    _log_init();

    log_info("Hello log.c\n");

    queue_t q;
    int ret = newqueue(&q, sizeof(int), 32);

    printf("Hello World!, %d\n", ret);
    
    return 0;
}


#ifdef __cplusplus
}
#endif /* __cplusplus */

