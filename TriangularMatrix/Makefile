all: TriangularMatrix main
	g++ main.o TriangularMatrix.o -o main.exe

TriangularMatrix: TriangularMatrix.cpp TriangularMatrix.h
	g++ -c TriangularMatrix.cpp

main: main.cpp TriangularMatrix.h
	g++ -c main.cpp

clean: 
	-rm *.o main.exe
