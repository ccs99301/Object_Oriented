#include <iostream>
#include "Account.h"
using namespace std;

class Investment: public Account
{
	public:
		Investment(double*,double*,double*,double*);
		void getPB();
		void getIB();

	private:
		double ETF[5];
		double A[5];
		double IVS[5];
		double CVS[5];
		double IR[5];
		double CV[5];
		double DIV[5];
};
