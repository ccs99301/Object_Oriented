#include <iostream>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
	num=NULL;
	size=0;
}

BigInt::BigInt(const int *data,int len)
{
	num=new char[len];
	for(int i=0;i<len;i++)
		num[i]=data[i]+48;
	size=len;
}

BigInt::BigInt(const BigInt& b)
{
	size=b.size;
	num=new char[size];
	for(int i=0;i<size;i++)
		num[i]=b.num[i];
}

BigInt::~BigInt()
{
	if(num!=NULL)
		delete [] num;
}

int BigInt::length()
{
	return size;
}

char* BigInt::getNum()
{
	return num;
}

char& BigInt::operator[](int index)
{
	if(index>=0&&index<size)
		return num[index];
}

BigInt& BigInt::operator++()
{
	num[size-1]++;
	if(num[size-1]==58)
	{
		num[size-1]='0';
		num[size-2]++;
	}
	return *this;
}

BigInt BigInt::operator++(int)
{
	BigInt tmp=*this;
	++*this;
	return tmp;
}

const BigInt& BigInt::operator=(const BigInt &b)
{
	delete [] num;
	size=b.size;
	num=new char[size];
	for(int i=0;i<size;i++)
		num[i]=b.num[i];
	return *this;
}
