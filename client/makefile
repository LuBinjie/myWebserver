main: main.o client.o
	gcc main.o client.o -o main

main.o: main.cpp
	gcc -c main.cpp -o main.o

client.o: client.cpp
	gcc -c client.cpp -o client.o

clean: 
	rm -rf *.o main
