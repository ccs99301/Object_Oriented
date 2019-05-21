#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Investment.h"
#include "Portfolio.h"
using namespace std;

int main()
{
	char cmd,filename[20];
	Portfolio p;
	cout<<"*** Portfolio Management menu ***"<<endl<<"I\tImport accounts from a file"<<endl;
	cout<<"S\tShow accounts (brief)"<<endl<<"E\tExport a banking report (to file)"<<endl;
	cout<<"M\tShow this menu"<<endl<<"Q\tQuit Programe"<<endl<<endl<<">";
	while(1)
	{
		cin>>cmd;
		if(cmd=='i'||cmd=='I')
		{
			cout<<"Enter filename: ";
			cin>>filename;
			p.importFile(filename);
			cout<<endl<<">";
		}
		else if(cmd=='s'||cmd=='S')
		{
			p.showAccounts();
			cout<<endl<<">";
		}
		else if(cmd=='e'||cmd=='E')
		{
			cout<<"Enter filename: ";
			cin>>filename;
			p.createReportFile(filename);
			cout<<endl<<">";
		}
		else if(cmd=='m'||cmd=='M')
		{
			cout<<"*** Portfolio Management menu ***"<<endl<<"I\tImport accounts from a file"<<endl;
			cout<<"S\tShow accounts (brief)"<<endl<<"E\tExport a banking report (to file)"<<endl;
			cout<<"M\tShow this menu"<<endl<<"Q\tQuit Programe"<<endl<<endl<<">";
		}
		else if(cmd=='q'||cmd=='Q')
			break;
		else
			cout<<"Invalid command"<<endl<<">";
	}
	cout<<"Goodbye!"<<endl;
	return 0;
}
