OBJECTS = scalegen.o main.o cluster

cluster : main.o scalegen.o
	gcc -o cluster main.o scalegen.o

main.o : main.c scalegen.h
	gcc -c main.c 
scalegen.o : scalegen.c scalegen.h
	gcc -c scalegen.c
clean:
	rm ${OBJECTS}
