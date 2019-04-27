#include <iostream>
#include "IntSet.h"
using namespace std;

IntSet::IntSet()
{
	for(int i=0;i<1000;i++)
		num[i]=-1e9;
}

IntSet::IntSet(int d)
{
	num[0]=d;
	for(int i=1;i<1000;i++)
		num[i]=-1e9;
}

bool IntSet::isEmpty() const
{
	if(num[0]==-1e9)
		return true;
	return false;
}

int IntSet::size() const
{
	int count=0;
	while(num[count]!=-1e9&&count<1000)
		count++;
	return count;
}

void IntSet::setPrint() const
{
	int s_size=size();
	if(s_size!=0)
	{
		cout << '{';
		for(int i=0;i<s_size-1;i++)
			cout << num[i] << ",";
		cout << num[s_size-1] << '}';
	}
	else
		cout << "{ }";
}

void IntSet::setAdd(int d)
{
	int s_size=size();
	if(s_size!=1000)
		num[s_size]=d;
}

IntSet IntSet::setUnion(const IntSet &b)
{
	IntSet tmp;
	int i,j,s1_size=size(),s2_size=b.size();
	for(i=0;i<s1_size;i++)
		tmp.num[i]=num[i];
	for(i=0;i<s2_size;i++)
	{
		for(j=0;j<s1_size;j++)
			if(b.num[i]==num[j])
				break;
		if(j==s1_size)
			tmp.setAdd(b.num[i]);
	}
	return tmp;
}

IntSet IntSet::setIntersection(const IntSet &b)
{
	IntSet tmp;
	int i,j,s1_size=size(),s2_size=b.size();
	for(i=0;i<s1_size;i++)
		for(j=0;j<s2_size;j++)
			if(num[i]==b.num[j])
				tmp.setAdd(num[i]);
	return tmp;
}

IntSet IntSet::relativeComplement(const IntSet &b)
{
	IntSet tmp;
	int i,j,s1_size=size(),s2_size=b.size();
	for(i=0;i<s1_size;i++)
	{
		for(j=0;j<s2_size;j++)
			if(b.num[j]==num[i])
				break;
		if(j==s2_size)
			tmp.setAdd(num[i]);
	}
	return tmp;
}

IntSet IntSet::symmetricDifference(const IntSet &b)
{
	IntSet tmp;
	int i,j,s1_size=size(),s2_size=b.size();
	for(i=0;i<s1_size;i++)
	{
		for(j=0;j<s2_size;j++)
			if(b.num[j]==num[i])
				break;
		if(j==s2_size)
			tmp.setAdd(num[i]);
	}
	for(i=0;i<s2_size;i++)
	{
		for(j=0;j<s1_size;j++)
			if(b.num[i]==num[j])
				break;
		if(j==s1_size)
			tmp.setAdd(b.num[i]);
	}
	return tmp;
}

bool IntSet::isEqualTo(const IntSet &b) const
{
	for(int i=0;i<1000;i++)
		if(num[i]!=b.num[i])
			return false;
	return true;
}
