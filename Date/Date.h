#include <iostream>
using namespace std;

class Date
{
	public:
		Date();
		Date(int,int,int);
		void Input();
		void Show();
		bool SetFormat(char);
		bool Set(int,int,int);
		int GetMonth();
		int GetDay();
		int GetYear();
		void Increment(int=1);
		int Compare(const Date&);

	private:
		int month;
		int day;
		int year;
		char format;
};
