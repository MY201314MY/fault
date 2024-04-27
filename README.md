```shell
CONFIG_KERNEL_ENTRY="__start"

```

```shell
z_early_memset(__bss_start, 0, __bss_end - __bss_start);
```

```c
int arch_swap(unsigned int key)

uintptr_t z_arm_pendsv_c(uintptr_t exc_ret)
```

```c
static inline int z_swap_irqlock(unsigned int key)
{
	int ret;
	z_check_stack_sentinel();
	ret = arch_swap(key);
	return ret;
}
```

```c
static ALWAYS_INLINE int z_swap(struct k_spinlock *lock, k_spinlock_key_t key)
{
	k_spin_release(lock);
	return z_swap_irqlock(key.key);
}
```

