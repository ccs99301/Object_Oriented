#include <iostream>
using namespace std;

class MyVector
{
	public:
		MyVector();
		MyVector(int,const double*);
		MyVector(const MyVector&);
		~MyVector();
		const MyVector& operator=(const MyVector&);
		friend ostream& operator<<(ostream&,const MyVector&);
		friend double operator*(const MyVector&,const MyVector&);
		friend MyVector operator*(const MyVector&,double);
		friend MyVector operator*(double,const MyVector&);
		friend MyVector operator+(const MyVector&,const MyVector&);

	private:
		double *num;
		int length;
};
