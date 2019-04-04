#include <iostream>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(int ID)
{
	int i;
	_ID=ID;
	for(i=0;i<100;i++)
	{
		_type[i]="";
		_amount[i]=0;
		_name[i]="";
	}
	_maxid=0;
}

void Transaction::writeTrans(string type,int amount,string name)
{
	_type[_maxid]=type;
	_amount[_maxid]=amount;
	_name[_maxid]=name;
	_maxid++;
}

void Transaction::printTrans()
{
	int i=0;
	cout << "Type: Create" <<endl;
	for(i=0;i<_maxid;i++)
	{
		cout << "Type: " << _type[i] << ' ' << _amount[i];
		if(_type[i]=="Transferred")
			cout << " to " << _name[i];
		cout << endl;
	}
}
