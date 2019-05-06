all: BigInt MyVector main
	g++ main.o BigInt.o MyVector.o -o main

BigInt: BigInt.cpp BigInt.h
	g++ -c BigInt.cpp

MyVector: MyVector.cpp MyVector.h
	g++ -c MyVector.cpp

main: main.cpp BigInt.h BigInt.cpp MyVector.h MyVector.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main
