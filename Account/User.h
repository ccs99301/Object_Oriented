#include <iostream>
using namespace std;

class User {
	public:
		User(const string,int);
		string getName();
		int getID();

	private:
		int _ID;
		string _name;
};

