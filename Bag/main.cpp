#include <iostream>
#include "Bag.h"
#include "Bag.cpp"
using namespace std;

int main()
{
	Bag<string> a;
	cout<<a.empty()<<endl;
	cout<<a.ended()<<endl;
	a.next();
	a.start();
	a.insert("a1");
	a.insert("a2");
	a.start();
	cout<<a.currentValue()<<endl;
	a.next();
	cout<<a.currentValue()<<endl;
	cout<<a.currentCount()<<endl;
	a.next();
	Bag<string> a_copy=a;
	cout<<a_copy.size()<<endl;
	a.insert("a3");
	cout<<a_copy.size()<<endl;
	Bag<string> a_as;
	a_as.insert("assigment1");
	a_as=a;
	cout<<a_as.size()<<endl;
	a_as.start();
	cout<<a_as.currentValue()<<endl;
	a_as.next();
	cout<<a_as.currentValue()<<endl;
	a_as.next();
	cout<<a_as.currentValue()<<endl;
	Bag<int> b;
	b.insert(10);
	b.insert(20);
	b.insert(20);
	b.insert(20);
	b.insert(30);
	b.insert(10);
	cout<<b.size()<<endl;
	cout<<b.uniqueSize()<<endl;
	cout<<b.erase(10)<<endl;
	cout<<b.eraseAll(20)<<endl;
	cout<<b.contains(20)<<endl;
	cout<<b.count(10)<<endl;
	Bag<string> c1,c2,c_result;
	c1.insert("duck");
	c1.insert("duck");
	c1.insert("goose");
	c1.insert("chicken");
	c1.insert("chicken");
	c2.insert("duck");
	c2.insert("goose");
	c2.insert("goose");
	c2.insert("chicken");
	c2.insert("chicken");
	combine(c1,c2,c_result);
	subtract(c1,c2,c_result);
	return 0;
}
