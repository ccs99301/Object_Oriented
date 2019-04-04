#include <iostream>
using namespace std;

class Account {
	public:
		Account(int);
		bool withdraw(int);
		bool deposit(int);
		bool transMoney(Account&,int);
		int getAmount();

	private:
		int _ID;
		int _amount;
		//int deduct;
		//int transfer;
};

