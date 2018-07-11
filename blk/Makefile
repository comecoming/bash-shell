obj-m := blk.o

all:
	make -C /lib/modules/`uname -r`/build modules M=`pwd`
clean:
	make -C /lib/modules/`uname -r`/build clean M=`pwd`
