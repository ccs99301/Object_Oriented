#include <iostream>
#include "Account.h"
#include "Savings.h"
using namespace std;

Savings::Savings(double cb,double ir)
{
	PB=0;
	IB=0;
	CB=cb;
	IR=ir;
	type='s';
	for(int i=0;i<20;i++)
	{
		f_name[i]='\0';
		l_name[i]='\0';
	}
}

void Savings::getPB()
{
	PB=CB*(1+IR);
	PB*=1000;
	if((int)PB%10>=5)
		PB+=5;
	PB/=1000;
}

void Savings::getIB()
{
	IB=CB;
	IB*=1000;
	if((int)IB%10>=5)
		IB+=5;
	IB/=1000;
}
