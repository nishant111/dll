target:exe

exe:application.o libdll.a
	gcc application.o -o exe -L . -ldll

application.o:application.c
	gcc -c application.c -o application.o

libdll.a:dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o

dll.o:dll.c
	gcc -c dll.c -o dll.o

dll_util.o:dll_util.c
	gcc -c dll_util.c -o dll_util.o

clean:
	rm dll.o
	rm dll_util.o
	rm application.o
	rm libdll.a
	rm exe
