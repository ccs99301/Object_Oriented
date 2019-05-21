#include <iostream>
#include "Account.h"
using namespace std;

class Portfolio
{
	public:
		Portfolio();
		~Portfolio();
		void list_resize(int);
		bool importFile(const char*);
		bool createReportFile(const char*);
		void showAccounts() const;

	private:
		Account **alist;
		int p_size;
		double IB;
};
