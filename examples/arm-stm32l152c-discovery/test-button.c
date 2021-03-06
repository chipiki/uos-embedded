/*
 * Testing GPIO input.
 */
#include <runtime/lib.h>
#include <kernel/uos.h>
#include <stm32l1/gpio.h>

ARRAY (task_space, 0x400);	/* Memory for task stack */

stm32l1_gpio_t user_button;

void task (void *arg)
{
	for (;;) {
		debug_printf ("Button value: %d\n", gpio_val(&user_button.gpioif));
	}
}

void uos_init (void)
{
    stm32l1_gpio_init(&user_button, GPIO_PORT_A, 0, GPIO_FLAGS_INPUT);
	task_create (task, "task", "task", 1, task_space, sizeof (task_space));
}
