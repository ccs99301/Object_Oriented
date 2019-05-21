#include <iostream>
#include "Account.h"
#include "Investment.h"
using namespace std;

Investment::Investment(double *a,double *ivs,double *cvs,double *ir)
{
	for(int i=0;i<5;i++)
	{
		A[i]=a[i];
		IVS[i]=ivs[i];
		CVS[i]=cvs[i];
		IR[i]=ir[i];
		CV[i]=(A[i]/IVS[i])*CVS[i];
		DIV[i]=IR[i]*A[i];
	}
	type='i';
	PB=0;
	IB=0;
	for(int i=0;i<20;i++)
	{
		f_name[i]='\0';
		l_name[i]='\0';
	}
}

void Investment::getPB()
{
	for(int i=0;i<5;i++)
	{
		ETF[i]=CV[i]+DIV[i];
		PB+=ETF[i];
	}
	PB*=1000;
	if((int)PB%10>=5)
		PB+=10;
	PB/=1000;
}

void Investment::getIB()
{
	IB=A[0]+A[1]+A[2]+A[3]+A[4];
	IB*=1000;
	if((int)IB%10>=5)
		IB+=5;
	IB/=1000;
}
