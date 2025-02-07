#include <linux/module.h>
int init_module(void)
{
	printk(KERN_INFO "hello : init_module : Hello DESD @ sunbeam\n");
	return 0;
}


void cleanup_module(void)
{
	printk(KERN_INFO "hello : cleanup_module :Bye bye DESD @sunbeam \n");
}
MODULE_INFO(license, "GPL");
MODULE_INFO(author, "Gyan");
MODULE_INFO(description, "This is hello module for desd @ sunbeam");

