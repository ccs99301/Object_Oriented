#include <iostream>
#include "User.h"
using namespace std;

User::User(string name,int id)
{
	_name=name;
	_ID=id;
	cout << "User constructed." << endl;
}

string User::getName()
{
	return _name;
}

int User::getID()
{
	return _ID;
}

