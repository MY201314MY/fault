#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(fault, LOG_LEVEL_DBG);

int _example_fault_t1(const struct shell *sh, size_t argc, char *argv[])
{
    int a = 1; 
	int b = 0;
    int c = a / b;

    LOG_DBG("c = %d", c);
    
	return 0;
}

int _example_fault_t2(const struct shell *sh, size_t argc, char *argv[])
{
    struct student {
        uint8_t age;
        char name[64];
    };

    struct student *stu = NULL;

    LOG_DBG("age = %d", stu->age);
    LOG_DBG("name = %s", stu->name);
    
	return 0;
}

int _example_fault_t3(const struct shell *sh, size_t argc, char *argv[])
{
    LOG_DBG("%s", CONFIG_KERNEL_ENTRY);

    extern char __bss_start[];
    extern char __bss_end[];
    LOG_DBG("%p", __bss_start);
    LOG_DBG("%p", __bss_end);
    
	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(fault_commands,
	SHELL_CMD(t1, NULL,
		"usage fault t1",
		_example_fault_t1),
    SHELL_CMD(t2, NULL,
		"usage fault t2",
		_example_fault_t2),
    SHELL_CMD(t3, NULL,
		"usage fault t3",
		_example_fault_t3),
	SHELL_SUBCMD_SET_END
);

SHELL_CMD_REGISTER(fault, &fault_commands,
		   "example for fault", NULL);
