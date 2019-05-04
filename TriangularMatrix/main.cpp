#include <iostream>
#include "TriangularMatrix.h"
using namespace std;

int main()
{
	Matrix m1,m2,m3;
	cout<<"value for m1"<<endl;
	m1.readMatrix();
	cout<<"value for m2"<<endl;
	m2.readMatrix();
	cout<<"m1 is:"<<m1<<endl<<endl;
	cout<<"m2 is:"<<m2<<endl<<endl;
	m3=m1+m2;
	cout<<"m3 is:"<<m3<<endl<<endl;
	m3=m2*5;
	cout<<"m3 is:"<<m3<<endl<<endl;
	m3-=m1;
	cout<<"m3 is:"<<m3<<endl<<endl;
	m3=m2*2*m1;
	cout<<"m3 is:"<<m3<<endl<<endl;
	double d=m1(1,2);
	cout<<d<<endl<<endl;
	cout<<m2(1,1)<<endl;
	return 0;
}
