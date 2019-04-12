#include <iostream>
#include <stdio.h>
#include "Date.h"
using namespace std;

Date::Date()
{
	month=1;
	day=1;
	year=2000;
	format='D';
}

Date::Date(int m,int d,int y)
{
	if(!Set(m,d,y))
	{
		month=1;
		day=1;
		year=2000;
	}
	format='D';
}

void Date::Input()
{
	int m,d,y;
	cout<<"Please input (Month / Day / Year) : ";
	scanf("%d/%d/%d",&m,&d,&y);
	while(!Set(m,d,y))
	{
		cout<<"Invalid date. Try again : ";
		scanf("%d/%d/%d",&m,&d,&y);
	}
}

void Date::Show()
{
	if(format=='D')
		cout<<month<<'/'<<day<<'/'<<year<<endl;
	else if(format=='T')
		printf("%02d/%02d/%02d\n",month,day,year%100);
	else if(format=='L')
	{
		if(month==1) cout<<"Jan ";
		else if(month==2) cout<<"Feb ";
		else if(month==3) cout<<"Mar ";
		else if(month==4) cout<<"Apr ";
		else if(month==5) cout<<"May ";
		else if(month==6) cout<<"Jun ";
		else if(month==7) cout<<"Jul ";
		else if(month==8) cout<<"Aug ";
		else if(month==9) cout<<"Sep ";
		else if(month==10) cout<<"Oct ";
		else if(month==11) cout<<"Nov ";
		else if(month==12) cout<<"Dec ";
		cout<<day<<", "<<year<<endl;
	}
}

bool Date::SetFormat(char f)
{
	if(f=='D'||f=='T'||f=='L')
	{
		format=f;
		return true;
	}
	return false;
}

bool Date::Set(int m,int d,int y)
{
	if(m>0&&d>0&&y>0&&m<13)
	{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d<32)
			{
				month=m;
				day=d;
				year=y;
				return true;
			}
		}
		else if(m==4||m==6||m==9||m==11)
		{
			if(d<31)
			{
				month=m;
				day=d;
				year=y;
				return true;
			}
		}
		else if(m==2)
		{
			if(d<29)
			{
				month=m;
				day=d;
				year=y;
				return true;
			}
		}
	}
	return false;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetDay()
{
	return day;
}

int Date::GetYear()
{
	return year;
}

void Date::Increment(int d)
{
	for(int i=0;i<d;i++)
	{
		if(month==12&&day==31)
		{
			month=1;
			day=1;
			++year;
		}
		else if((month==1||month==3||month==5||month==7||month==8||month==10)&&day==31)
		{
			++month;
			day=1;
		}
		else if((month==4||month==6||month==9||month==11)&&day==30)
		{
			++month;
			day=1;
		}
		else if(month==2&&day==28)
		{
			++month;
			day=1;
		}
		else
			++day;
	}
}

int Date::Compare(const Date &date)
{
	if(year>date.year)
		return 1;
	else if(year<date.year)
		return -1;
	else if(month>date.month)
		return 1;
	else if(month<date.month)
		return -1;
	else if(day>date.day)
		return 1;
	else if(day<date.day)
		return -1;
	else
		return 0;
}

