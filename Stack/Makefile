all: stack.o stackHelper.o StackLinkList.o execute clean 

execute: stack.o stackHelper.o StackLinkList.o
	gcc -Wall -o execute stack.o stackHelper.o StackLinkList.o
stack.o: stack.c
	gcc -c -Wall stack.c
stackHelper.o: stackHelper.c
	gcc -c -Wall stackHelper.c
StackLinkList.o: StackLinkList.c
	gcc -c -Wall StackLinkList.c
clean:
	@echo "Cleaning up"
	rm *.o