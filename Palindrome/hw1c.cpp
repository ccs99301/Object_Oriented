#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	int left=0,right=0;
	string text;
	cout << "Enter the texts : ";
	getline(cin,text,'\n');
	right=text.size()-1;
	while(1)
	{
		if(text[left]>='a'&&text[left]<='z'||text[left]>='A'&&text[left]<='Z'||left>=text.size())
			break;
		left++;
	}
	while(1)
	{
		if(text[right]>='a'&&text[right]<='z'||text[right]>='A'&&text[right]<='Z'||right==0)
			break;
		right--;
	}
	if(text[left]==toupper(text[right])||text[left]==tolower(text[right]))
	{
		while(left<right)
		{
			while(1)
			{
				left++;
				if(text[left]>='a'&&text[left]<='z'||text[left]>='A'&&text[left]<='Z'||left>=text.size())
					break;
			}
			while(1)
			{
				right--;
				if(text[right]>='a'&&text[right]<='z'||text[right]>='A'&&text[right]<='Z'||right==0)
					break;
			}
			if(text[left]!=toupper(text[right])&&text[left]!=tolower(text[right]))
				break;
		}
	}
	if(left>=right&&left<text.size())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

