#include <iostream>
#include "Account.h"
#include "Checking.h"
using namespace std;

Checking::Checking(double cb)
{
	PB=0;
	IB=0;
	CB=cb;
	type='c';
	for(int i=0;i<20;i++)
	{
		f_name[i]='\0';
		l_name[i]='\0';
	}
}

void Checking::getPB()
{
	PB=CB+0.1;
	PB*=1000;
	if((int)PB%10>=5)
		PB+=5;
	PB/=1000;
}

void Checking::getIB()
{
	IB=CB;
	IB*=1000;
	if((int)IB%10>=5)
		IB+=5;
	IB/=1000;
}
