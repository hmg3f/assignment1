CC = g++

main: main.o assignment-1.o
	$(CC) -o arrays main.o assignment-1.o

main.o: main.cpp assignment-1.hpp
	$(CC) -c main.cpp

assignment-1.o: assignment-1.hpp

clean:
	rm assignment-1.o main.o arrays
