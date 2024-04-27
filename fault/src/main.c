/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/uart.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#define BRUCE_STACK_SIZE 1024
K_THREAD_STACK_DEFINE(bruce_stack, BRUCE_STACK_SIZE);
struct k_thread bruce_thread_data = {0};

int sum(int a, int b)
{
	int c = a + b;

	return c;
}

void thread_bruce_entry()
{
	int s1 = sum(2, 3);
	int s2 = -1;

	while(1)
	{
		k_sleep(K_SECONDS(2));
		LOG_WRN("sum : %d\r\n", sum(6, 7));
		LOG_DBG("size : %d", bruce_thread_data.stack_info.size);
	}
}
int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD);

	k_thread_create(&bruce_thread_data,
		bruce_stack,
		K_THREAD_STACK_SIZEOF(bruce_stack),
		thread_bruce_entry,
		NULL, NULL, NULL,
		5, 0, K_NO_WAIT);
	
	return 0;
}
