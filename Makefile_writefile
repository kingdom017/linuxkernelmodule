obj-m += hello.o                         #由此目标文件生成模块
CURRENT_PATH := $(shell pwd)             #当前所在的路径
LINUX_KERNEL := $(shell uname -r)        #内核的版本号

#内核代码所在的路径
LINUX_KERNEL_PATH := /usr/src/linux-headers-$(LINUX_KERNEL)

#编译
all:
  make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

#清除编译生成的文件
clean:
  make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
