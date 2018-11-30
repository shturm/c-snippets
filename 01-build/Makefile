CC ?= cc # or gcc
CCFLAGS ?= -Wall # or define them individually

# $@ is the name of the job, e.g. "all"

all:
	$(CC) $(CCFLAGS) -c app.core.c -o app.core.o
	$(CC) $(CCFLAGS) app.exec.c app.core.o

clean:
	rm -rf *.a 
	rm -rf *.o
	rm -rf a.out

rebuild: clean all

rebuildrun: rebuild
	./a.out 1 2 3