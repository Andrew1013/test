obj-m := parlelport.o
KERNEL_DIR=/lib/modules/`uname -r`/build
MODULE_DIR := $(shell pwd)

modules:
	make -C $(KERNEL_DIR) M=$(MODULE_DIR) modules
#	gcc nothing.c -o nothing.out
