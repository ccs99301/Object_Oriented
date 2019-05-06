#include<iostream>
#include "BigInt.h"
#include "MyVector.h"
using namespace std;
int main()
{
	//Part1
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	BigInt A(a, sizeof(a) / sizeof(a[0]));
	cout<<A.length()<<endl;//印出50
	cout<<A.getNum()<<endl;//印出12345678901234567890123456789012345678901234567890
	cout<<A[0]<<endl;//印出1
	
	BigInt B;
	B = A;//assignment operator
	cout<<B.length()<<endl;//印出50
	cout<<B.getNum()<<endl;//印出12345678901234567890123456789012345678901234567890
	
	BigInt C = B;//copy constructor
	cout<<B.length()<<endl;//印出50
	cout<<B.getNum()<<endl;//印出12345678901234567890123456789012345678901234567890
	
	C++;
	cout<<C.length()<<endl;//印出50
	cout<<C.getNum()<<endl;//印出12345678901234567890123456789012345678901234567891
	
	++C;
	cout<<C.length()<<endl;//印出50
	cout<<C.getNum()<<endl;//印出12345678901234567890123456789012345678901234567892
	
	//Part2
	double V_1[] = {1, 2, 3, 4, 6};
	MyVector V1(sizeof(V_1) / sizeof(V_1[0]), V_1);
	cout<<V1<<endl;//印出<1, 2, 3, 4, 6>
	
	double V_2[] = {7, 6, 5, 3, 2};
	MyVector V2(sizeof(V_2) / sizeof(V_2[0]), V_2);
	cout<<V2<<endl;//印出<7, 6, 5, 3, 2>
	
	cout<<V1<<"*"<<V2<<"="<<V1*V2<<endl;//印出<1, 2, 3, 4, 6>*<7, 6, 5, 3, 2>=58
	
	cout<<V1<<"*"<<"3"<<"="<<V1*3<<endl;//印出<1, 2, 3, 4, 6>*3=<3, 6, 9, 12, 18>
	
	cout<<V1<<"+"<<V2<<"="<<V1+V2<<endl;//印出<1, 2, 3, 4, 6>+<7, 6, 5, 3, 2>=<8, 8, 8, 7, 8>
	
	MyVector V3;
	cout<<V3<<endl;//印出<>
	V3 = V1;
	cout<<V3<<endl;//印出<1, 2, 3, 4, 6>
	
	MyVector V4 = V3;
	cout<<V4<<endl;//印出<1, 2, 3, 4, 6>
	return 0;
}
