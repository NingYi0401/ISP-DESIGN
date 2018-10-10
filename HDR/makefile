main: tool.o
	gcc -g main.c -o main tool.o

tool.0:
	gcc -g -c ./tool.c -o tool.o -I/typedef.h -I/HDR.h

clean:
	rm -f main *.o *~ *.gch
