CC=g++
CFLAGS= -c -Wall -fdiagnostics-color
LDFLAGS= -lwiringPi -lpthread -fdiagnostics-color

all: OneWire

OneWire: main.o OneWire.o
	$(CC) $(LDFLAGS) main.o OneWire.o -o OneWire

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

OneWire.o: OneWire.cpp
	$(CC) $(CFLAGS) -c OneWire.cpp

clean:
	rm -rf *.o OneWire
