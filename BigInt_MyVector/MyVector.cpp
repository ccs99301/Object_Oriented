#include <iostream>
#include "MyVector.h"
using namespace std;

MyVector::MyVector()
{
	num=NULL;
	length=0;
}

MyVector::MyVector(int len,const double *data)
{
	length=len;
	num=new double[len];
	for(int i=0;i<len;i++)
		num[i]=data[i];
}

MyVector::MyVector(const MyVector &b)
{
	length=b.length;
	num=new double[length];
	for(int i=0;i<length;i++)
		num[i]=b.num[i];
}

MyVector::~MyVector()
{
	if(num!=NULL)
		delete [] num;
}

const MyVector& MyVector::operator=(const MyVector &b)
{
	length=b.length;
	delete [] num;
	num=new double[length];
	for(int i=0;i<length;i++)
		num[i]=b.num[i];
}

ostream& operator<<(ostream &out,const MyVector &v)
{
	out<<'<';
	for(int i=0;i<v.length-1;i++)
		out<<v.num[i]<<", ";
	if(v.length!=0)
		out<<v.num[v.length-1];
	out<<'>';
	return out;
}

double operator*(const MyVector &a,const MyVector &b)
{
	double result=0;
	if(a.length==b.length)
		for(int i=0;i<a.length;i++)
			result+=a.num[i]*b.num[i];
	return result;
}

MyVector operator*(const MyVector &a,double b)
{
	MyVector tmp=a;
	for(int i=0;i<a.length;i++)
		tmp.num[i]*=b;
	return tmp;
}

MyVector operator*(double b,const MyVector &a)
{
	MyVector tmp=a;
	for(int i=0;i<a.length;i++)
		tmp.num[i]*=b;
	return tmp;
}

MyVector operator+(const MyVector &a,const MyVector &b)
{
	MyVector tmp=a;
	if(a.length==b.length)
		for(int i=0;i<a.length;i++)
			tmp.num[i]+=b.num[i];
	return tmp;
}
