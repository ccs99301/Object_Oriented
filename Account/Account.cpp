#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int ID)
{
	_ID=ID;
	_amount=0;
	cout << "Account constructed." << endl;
}

bool Account::deposit(int amount)
{
	if(amount<0)
	{
		cout << "The amount most be positive." << endl;
		return false;
	}
	else
	{
		_amount+=amount;
		return true;
	}
}

bool Account::withdraw(int amount)
{
	if(_amount<amount)
	{
		cout << "You have not enough money." << endl;
		return false;
	}
	else
	{
		_amount-=amount;
		return true;
	}
}

bool Account::transMoney(Account &accountB,int amount)
{
	if(accountB._ID==0)
	{
		cout << "Error account." << endl;
		return false;
	}
	else if(_amount<amount)
	{
		cout << "You have not enough money." << endl;
		return false;
	}
	else
	{
		_amount-=amount;
		accountB._amount+=amount;
		return true;
	}
}

int Account::getAmount()
{
	return _amount;
}

