#include <iostream>
using namespace std;

class BigInt
{
	public:
		BigInt();
		BigInt(const int*,int);
		BigInt(const BigInt&);
		~BigInt();
		int length();
		char* getNum();
		char& operator[](int);
		BigInt& operator++();
		BigInt operator++(int);
		const BigInt& operator=(const BigInt&);

	private:
		char *num;
		int size;
};
