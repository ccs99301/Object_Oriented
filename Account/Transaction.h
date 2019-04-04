#include <iostream>
using namespace std;

class Transaction
{
	public:
		Transaction(int);
		void writeTrans(string,int,string);
		void printTrans();
	
	private:
		int _ID;
		string _type[100];
		int _amount[100];
		string _name[100];
		int _maxid;
};
