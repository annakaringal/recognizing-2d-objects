CC = g++
VERS = -std=c++11

all: p1 p2 p3 p4

p1: p1.o BinaryImage.o Validation.o Image.o Pgm.o
	$(CC) p1.o BinaryImage.o Validation.o Image.o Pgm.o -o p1

p2: p2.o ObjectLabeler.o Image.o Pgm.o
	$(CC) p2.o ObjectLabeler.o Image.o Pgm.o -o p2

p3: p3.o Object.o ImageObjectDatabase.o Validation.o Image.o Pgm.o Line.o
	$(CC) p3.o Object.o ImageObjectDatabase.o Validation.o Image.o Pgm.o Line.o -o p3

p4: p4.o Object.o ImageObjectDatabase.o Validation.o Image.o Pgm.o Line.o
	$(CC) p4.o Object.o ImageObjectDatabase.o Validation.o Image.o Pgm.o Line.o -o p4

p1.o: p1.cpp
	$(CC) -c p1.cpp

p2.o: p2.cpp
	$(CC) -c p2.cpp

p3.o: p3.cpp
	$(CC) -c p3.cpp

p4.o: p4.cpp
	$(CC) -c p4.cpp

BinaryImage.o: BinaryImage.cpp
	$(CC) -c BinaryImage.cpp

ImageObjectDatabase.o: ImageObjectDatabase.cpp
	$(CC) $(VERS) -c ImageObjectDatabase.cpp

Object.o: Object.cpp
	$(CC) -c Object.cpp

ObjectLabeler.o: ObjectLabeler.cpp
	$(CC) -c ObjectLabeler.cpp

Validation.o: Validation.cpp
	$(CC) -c Validation.cpp

Image.o: pgm/Image.cpp
	$(CC) -c pgm/Image.cpp

Pgm.o: pgm/Pgm.cpp
	$(CC) -c pgm/Pgm.cpp

Line.o: pgm/Line.cpp
	$(CC) -c pgm/Line.cpp

clean:
	rm *o p1 p2 p3 p4