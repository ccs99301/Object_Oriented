#include <iostream>
#include "Account.h"
using namespace std;

class Savings: public Account
{
	public:
			Savings(double,double);
			void getPB();
			void getIB();

	private:
			double CB;
			double IR;
};
