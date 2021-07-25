target:exe

exe:application.o libdll.a
	gcc application.o -o exe -L . -ldll

exe1:application.o dll.o
	gcc -o exe1 application.o dll.o

application.o:application.c
	gcc -g -c application.c -o application.o

libdll.a:dll.o
	ar rs libdll.a dll.o

dll.o:dll.c
	gcc -g -c dll.c -o dll.o

clean:
	rm dll.o
	rm application.o
	rm libdll.a
	rm exe
