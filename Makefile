OBJS = main.o data_linkstack.o op_linkstack.o calc_linkstack.o linklist.o
CFLAGS = -Wall -g -c -DDEBUG 

main:$(OBJS)

.PHONY:clean
clean:
	rm $(OBJS) main

