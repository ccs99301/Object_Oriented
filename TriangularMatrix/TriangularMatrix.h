#include <iostream>
using namespace std;

class Matrix
{
	public:
		Matrix();
		Matrix(int);
		Matrix(const Matrix&);
		~Matrix();
		void readMatrix();
		int size() const;
		const Matrix& operator=(const Matrix&);
		friend ostream& operator<<(ostream&,const Matrix&);
		double operator()(int,int) const;
		friend Matrix operator+(const Matrix&,const Matrix&);
		friend Matrix operator-(const Matrix&,const Matrix&);
		friend Matrix operator*(const Matrix&,const Matrix&);
		friend Matrix operator*(const Matrix&,double);
		friend Matrix operator*(double,const Matrix&);
		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(double);

	private:
		double *element;
		int n;
		int ud;
};
