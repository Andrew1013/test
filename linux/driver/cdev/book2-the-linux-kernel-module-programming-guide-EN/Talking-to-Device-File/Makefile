obj-m += chardev.o

KERNEL_DIR=/lib/modules/`uname -r`/build
MODULE_DIR := $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(MODULE_DIR) modules
#	gcc nothing.c -o nothing.out
clean:
	make -C $(KERNEL_DIR) M=$(MODULE_DIR) clean

