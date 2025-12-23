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

/* Private define 0 ----------------------------------------------------------*/
/* Private macro 0 -----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private define 1 ----------------------------------------------------------*/
/* Private macro 1 -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private define 2 ----------------------------------------------------------*/
/* Private macro 2 -----------------------------------------------------------*/
/* Private function code -----------------------------------------------------*/
static int _log_init(void)
{
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

