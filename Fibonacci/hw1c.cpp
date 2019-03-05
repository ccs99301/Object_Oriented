#include <bits/stdc++.h>
using namespace std;

void big_add(int num[3][100])
{
	int i;
	for(i=0;i<100;i++)
		num[2][i]=num[0][i]+num[1][i];
	for(i=0;i<99;i++)
	{
		num[2][i+1]+=num[2][i]/10;
		num[2][i]%=10;
	}
}

void big_print(int *a)
{
	int i=99;
	while(a[i]==0)
		i--;
	for(i;i>=0;i--)
		cout << a[i];
	cout << endl;
}

int main(int argc,char *argv[])
{
	int fib[3][100],n=atoi(argv[1]),i;
	if(argc<2)
	{
		cout << "usage: hw1c [number]" << endl;
		exit(1);
	}
	for(i=1;i<100;i++)
	{
		fib[0][i]=0;
		fib[1][i]=0;
		fib[2][i]=0;
	}
	fib[0][0]=1;
	fib[1][0]=1;
	fib[2][0]=2;
	if(n<4&&n>0)
		cout << fib[n-1][0] << endl;
	else
	{
		for(n;n>3;n--)
		{
			for(i=0;i<100;i++)
			{
				fib[0][i]=fib[1][i];
				fib[1][i]=fib[2][i];
			}
			big_add(fib);
		}
		big_print(fib[2]);
	}
	return 0;
}
