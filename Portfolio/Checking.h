#include <iostream>
#include "Account.h"
using namespace std;

class Checking: public Account
{
	public:
		Checking(double);
		void getPB();
		void getIB();

	private:
		double CB;
};
