#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int simple_init(void) {
    printk(KERN_INFO "Loading my first module\n");
    return 0;
}

int simple_exit(void) {
    printk(KERN_INFO "Removing my first module\n");
    return 0;
}

