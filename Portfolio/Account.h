#pragma once
#include <iostream>
using namespace std;

class Account
{
	friend class Portfolio;
	public:
		virtual void getPB(); 
		virtual void getIB();

	protected:
		char f_name[20];
		char l_name[20];
		char type;
		double PB;
		double IB;
};
