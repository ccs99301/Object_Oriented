all: Account Savings Checking Investment Portfolio main
	g++ main.o Account.o Savings.o Checking.o Investment.o Portfolio.o -o main

Account: Account.cpp Account.h
	g++ -c Account.cpp

Savings: Savings.cpp Savings.h Account.cpp Account.h
	g++ -c Savings.cpp

Checking: Checking.cpp Checking.h Account.cpp Account.h
	g++ -c Checking.cpp

Investment: Investment.cpp Investment.h Account.cpp Account.h
	g++ -c Investment.cpp

Portfolio: Portfolio.cpp Portfolio.h Account.cpp Account.h
	g++ -c Portfolio.cpp

main: main.cpp Savings.h Savings.cpp Checking.h Checking.cpp Investment.h Investment.cpp Portfolio.h Portfolio.cpp Account.h Account.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main
