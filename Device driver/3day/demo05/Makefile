obj-m = splitfile.o
splitfile-objs = file1.o file2.o file3.o

modules:
	make -C /lib/modules/`uname -r`/build M=`pwd` modules

clean:
	make -C /lib/modules/`uname -r`/build M=`pwd` clean
