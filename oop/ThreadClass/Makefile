.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
ALL=threadtest
all:$(ALL)
OBJS=Thread.o threadtest.o
.c.o:
	$(CC) $(CPPFLAGS) -c $<

threadtest:$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

clean:
	rm -f $(ALL) *.o
