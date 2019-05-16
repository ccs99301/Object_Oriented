all: HuffmanTree Node main
	g++ main.o HuffmanTree.o Node.o -o main.exe
	
HuffmanTree: HuffmanTree.cpp HuffmanTree.h Node.h
	g++ -c HuffmanTree.cpp

Node: Node.cpp Node.h
	g++ -c Node.cpp

main: main.cpp HuffmanTree.h
	g++ -c main.cpp

clean: 
	-rm *.o main.exe
