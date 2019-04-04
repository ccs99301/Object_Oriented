#include <iostream>
#include "Account.h"
#include "User.h"
#include "Transaction.h"
using namespace std;

int main()
{
	int mode=0,amount=0;
	Account a1(1),a2(2);
	User u1("john",1),u2("mary",2);
	Transaction t1(1);
	while(1)
	{
		cout << "What john to do ?" << endl
				<< "(1) Deposit" << endl
				<< "(2) Withdraw" <<endl
				<< "(3) Transfer" <<endl
				<< "(4) Print " << u1.getName() <<" Transaction" << endl
				<< "(0) Exit" << endl;
		cin >> mode;
		if(mode==1)
		{
			cout << "Amount? ";
			cin >> amount;
			if(a1.deposit(amount)==true)
			{
				cout << u1.getName() << " have " << a1.getAmount() << endl;
				t1.writeTrans("Deposit",amount,"");
			}
		}
		else if(mode==2)
		{
			cout << "Amount? ";
			cin >> amount;
			if(a1.withdraw(amount)==true)
			{
				cout << u1.getName() << " have " << a1.getAmount() << endl;
				t1.writeTrans("Withdraw",amount,"");
			}
		}
		else if(mode==3)
		{
			cout << "Amount to " << u2.getName() << " ?" << endl;
			cin >> amount;
			if(a1.transMoney(a2,amount)==true)
			{
				cout << u1.getName() << " have " << a1.getAmount() << endl;
				t1.writeTrans("Transferred",amount,u2.getName());
			}
		}
		else if(mode==4)
			t1.printTrans();
		else if(mode==0)
			break;
	}
	return 0;
}

