#include <iostream>
#include "TriangularMatrix.h"
using namespace std;

Matrix::Matrix()
{
	n=0;
	ud=-1;
	cout << "Matrix constructed" << endl;
}

Matrix::Matrix(int x)
{
	n=x;
	ud=-1;
	cout << "Matrix constructed" << endl;
}

Matrix::Matrix(const Matrix &m)
{
	int i,len=n*(n+1)/2;
	n=m.n;
	element=new double[len];
	for(i=0;i<len;i++)
		element[i]=m.element[i];
	cout << "Matrix copy constructed" << endl;
}

Matrix::~Matrix()
{
	delete[] element;
	n=0;
	ud=0;
	cout << "Matrix destructed" << endl;
}

void Matrix::readMatrix()
{
	int i,len;
	if(n==0)
	{
		cout << "specify number of rows." << endl;
		while(n<1)
		{
			cin >> n;
			if(n<1)
				cout << "Please input the number > 0" << endl;
		}
	}
	cout << "is upper or lower triangular: (upper: 1, lower: 0)" << endl;
	while(ud!=0&&ud!=1)
	{
		cin >> ud;
		if(ud!=0&&ud!=1)
			cout << "Please input 1 or 0" << endl;
	}
	cout << "input elements of the matrix." << endl;
	len=n*(n+1)/2;
	element=new double[len];
	for(i=0;i<len;i++)
		cin >> element[i];
}

int Matrix::size() const
{
	return n;
}

const Matrix& Matrix::operator=(const Matrix &m)
{
	int i,len=m.n*(m.n+1)/2;
	delete[] element;
	element=new double[len];
	n=m.n;
	ud=m.ud;
	for(i=0;i<len;i++)
		element[i]=m.element[i];
	return *this;
}

ostream& operator<<(ostream &out,const Matrix &m)
{
	int i,j,t=0;
	out << endl;
	for(i=0;i<m.n;i++)
	{
		if(m.ud==0)
		{
			for(j=0;j<=i;j++)
			{
				out << m.element[t] << '\t';
				t+=1;
			}
			for(j=0;j<m.n-i-1;j++)
				out << '0' << '\t';
		}
		else
		{
			for(j=i;j>0;j--)
				out << '0' << '\t';
			for(j=m.n-i;j>0;j--)
			{
				out << m.element[t] << '\t';
				t+=1;
			}
		}
		out << endl;
	}
	return out;
}

double Matrix::operator()(int i,int j) const
{
	if(ud==0&&i>=j||ud==1&&i<=j)
		return element[(i-1)*i/2+(j-1)];
	else
		return 0.0;
}

Matrix operator+(const Matrix &lt,const Matrix &rt)
{
	int i,len=lt.n*(lt.n+1)/2;
	Matrix tmp;
	if(lt.n==rt.n&&lt.ud==rt.ud)
	{
		tmp.n=lt.n;
		tmp.ud=lt.ud;
		for(i=0;i<len;i++)
			tmp.element[i]=lt.element[i]+rt.element[i];
	}
	else
		cout << "Matrix size or type is different" << endl;
	return tmp;
}

Matrix operator-(const Matrix &lt,const Matrix &rt)
{
	int i,len=lt.n*(lt.n+1)/2;
	Matrix tmp;
	if(lt.n==rt.n&&lt.ud==rt.ud)
	{
		tmp.n=lt.n;
		tmp.ud=lt.ud;
		for(i=0;i<len;i++)
			tmp.element[i]=lt.element-rt.element;
	}
	else
		cout << "Matrix size or type is different" << endl;
	return tmp;
}

Matrix operator*(const Matrix &lt,const Matrix &rt)
{
	int i,j,k;
	Matrix tmp;
	if(lt.n==rt.n&&lt.ud==rt.ud)
	{
		tmp.n=lt.n;
		tmp.ud=lt.ud;
		for(i=0;i<lt.n;i++)
			for(j=0;j<lt.n;j++)
				for(k=0;k<lt.n;k++)
					if(lt.ud==0&&i>=k&&k>=j||lt.ud==1&&i<=k&&k<=j)
						tmp.element[i*(i+1)/2+j]+=lt.element[i*(i+1)/2+k]*rt.element[k*(k+1)/2+j];
	}
	else
		cout << "Matrix size or type is different" << endl;
	return tmp;
}

Matrix operator*(const Matrix &lt,double s)
{
	int i,len=lt.n*(lt.n+1)/2;
	Matrix tmp;
	tmp.n=lt.n;
	tmp.ud=lt.ud;
	for(i=0;i<len;i++)
		tmp.element[i]=lt.element[i]*s;
	return tmp;
}

Matrix operator*(double s,const Matrix &rt)
{
	int i,len=rt.n*(rt.n+1)/2;
	Matrix tmp;
	tmp.n=rt.n;
	tmp.ud=rt.ud;
	for(i=0;i<len;i++)
		tmp.element[i]=s*rt.element[i];
	return tmp;
}

Matrix& Matrix::operator+=(const Matrix &m)
{
	int i,len=n*(n+1)/2;
	if(n==m.n&&ud==m.ud)
		for(i=0;i<len;i++)
			element[i]+=m.element[i];
	else
		cout << "Matrix size or type is different" << endl;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix &m)
{
	int i,len=n*(n+1)/2;
	if(n==m.n&&ud==m.ud)
		for(i=0;i<len;i++)
			element[i]-=m.element[i];
	else
		cout << "Matrix size or type is different" << endl;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix &m)
{
	int i,j,k,len=n*(n+1)/2;
	Matrix tmp;
	if(n==m.n&&ud==m.ud)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(ud==0&&i>=k&&k>=j||ud==1&&i<=k&&k<=j)
						tmp.element[i*(i+1)/2+j]+=element[i*(i+1)/2+k]*m.element[k*(k+1)/2+j];
		for(i=0;i<len;i++)
			element[i]=tmp.element[i];
	}
	else
		cout << "Matrix size or type is different" << endl;
	return *this;
}

Matrix& Matrix::operator*=(double s)
{
	int i,len=n*(n+1)/2;
	for(i=0;i<len;i++)
		element[i]*=s;
	return *this;
}
