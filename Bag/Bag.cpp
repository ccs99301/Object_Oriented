#include <iostream>
#include "Bag.h"
using namespace std;

template<class Type>void combine(Bag<Type> &bag1,Bag<Type> &bag2,Bag<Type> &result)
{
	bool ac=0;
	Item<Type> *tmp=bag1.item->nxt;
	Bag<Type> newb;
	while(tmp!=bag1.item)
	{
		ac=newb.insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	tmp=bag2.item->nxt;
	while(tmp!=bag2.item)
	{
		ac=newb.insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	result=newb;
}

template<class Type>void subtract(Bag<Type> &bag1,Bag<Type> &bag2,Bag<Type> &result)
{
	bool ac=0;
	int de=0;
	Item<Type> *tmp=bag1.item->nxt;
	Bag<Type> newb;
	while(tmp!=bag1.item)
	{
		ac=newb.insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	tmp=bag2.item->nxt;
	while(tmp!=bag2.item)
	{
		de=newb.erase(tmp->value);
		tmp=tmp->nxt;
	}
	result=newb;
}

template<class Type>
Item<Type>::Item()
{
	nxt=NULL;
	pre=NULL;
}

template<class Type>
Item<Type>::Item(Type x)
{
	nxt=NULL;
	pre=NULL;
	value=x;
}

template<class Type>
Bag<Type>::Bag()
{
	item=new Item<Type>();
	item->nxt=item;
	item->pre=item;
	finger=item;
	cout << "Bag constructed" << endl;
}

template<class Type>
Bag<Type>::~Bag()
{
	Item<Type> *tmp=item->nxt;
	while(tmp!=item)
	{
		tmp=tmp->nxt;
		delete tmp->pre;
	}
	delete item;
	cout << "Bag destructed" << endl;
}
	
template<class Type>
Bag<Type>::Bag(const Bag<Type> &old)
{
	bool ac=0;
	Item<Type> *tmp=old.item->nxt;
	item=new Item<Type>();
	item->nxt=item;
	item->pre=item;
	finger=item;
	while(tmp!=old.item)
	{
		ac=this->insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	cout << "Bag copy constructed" << endl;
}

template<class Type>
Bag<Type>& Bag<Type>::operator=(const Bag<Type> &old)
{
	bool ac=0;
	Item<Type> *tmp=item->nxt;
	while(tmp!=item)
	{
		tmp=tmp->nxt;
		delete tmp->pre;
	}
	item->nxt=item;
	item->pre=item;
	tmp=old.item->nxt;
	while(tmp!=old.item)
	{
		ac=this->insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	return *this;
}

template<class Type>
bool Bag<Type>::empty() const
{
	if(item->nxt==item)
		return true;
	return false;
}

template<class Type>
int Bag<Type>::size() const
{
	int cnt=0;
	Item<Type> *tmp=item->nxt;
	while(tmp!=item)
	{
		cnt+=1;
		tmp=tmp->nxt;
	}
	return cnt;
}

template<class Type>
int Bag<Type>::uniqueSize() const
{
	int cnt=1;
	Item<Type> *tmp,*now=item->nxt;
	while(now!=item)
	{
		tmp=item->nxt;
		while(tmp->value!=now->value)
		{
			tmp=tmp->nxt;
			if(tmp==now)
				cnt+=1;
		}
		now=now->nxt;
	}
	return cnt;
}

template<class Type>
bool Bag<Type>::insert(const Type &x)
{
	Item<Type> *newi=new Item<Type>(x);
	newi->nxt=item;
	newi->pre=item->pre;
	item->pre->nxt=newi;
	item->pre=newi;
	finger=item;
	return true;
}

template<class Type>
int Bag<Type>::erase(const Type &x)
{
	int cnt=1;
	Item<Type> *tmp=item->nxt;
	while(tmp->value!=x)
	{
		if(tmp->nxt==item)
			return 0;
		tmp=tmp->nxt;
		cnt+=1;
	}
	tmp->pre->nxt=tmp->nxt;
	tmp->nxt->pre=tmp->pre;
	delete tmp;
	finger=item;
	return cnt;
}

template<class Type>
int Bag<Type>::eraseAll(const Type &x)
{
	int cnt=0;
	Item<Type> *tmp=item->nxt,*del;
	while(tmp!=item)
	{
		tmp=tmp->nxt;
		del=tmp->pre;
		if(del->value==x)
		{
			del->pre->nxt=tmp;
			tmp->pre=del->pre;
			delete del;
			cnt+=1;
		}
	}
	finger=item;
	return cnt;
}

template<class Type>
bool Bag<Type>::contains(const Type &x)
{
	Item<Type> *tmp=item->nxt;
	while(tmp!=item)
	{
		if(tmp->value==x)
			return true;
		tmp=tmp->nxt;
	}
	return false;
}

template<class Type>
int Bag<Type>::count(const Type &x)
{
	int cnt=0;
	Item<Type> *tmp=item->nxt;
	while(tmp!=item)
	{
		if(tmp->value==x)
			cnt+=1;
		tmp=tmp->nxt;
	}
	return cnt;
}

template<class Type>
void Bag<Type>::start()
{
	if(item->nxt==item)
		cout << "Please input item" << endl;
	else
		finger=item->nxt;
}

template<class Type>
void Bag<Type>::next()
{
	if(finger==item)
		cout << "Please initializes" << endl;
	else
		finger=finger->nxt;
}

template<class Type>
bool Bag<Type>::ended() const
{
	if(finger==item)
		return true;
	return false;
}

template<class Type>
const Type Bag<Type>::currentValue() const
{
	if(finger==item)
	{
		cout << "Please initializes" << endl;
		return item->value;
	}
	else
		return finger->value;
}

template<class Type>
int Bag<Type>::currentCount() const
{
	int cnt=0;
	Item<Type> *tmp=item;
	if(finger==item)
		cout << "Please initializes" << endl;
	else
	{
		while(tmp!=finger)
		{
			tmp=tmp->nxt;
			cnt+=1;
		}
	}
	return cnt;
}

/*template<class Type>void combine(Type &bag1,Type &bag2,Type &result)
{
	bool ac=0;
	int i=result.size();
	Item<Type> *tmp=bag1.item->nxt;
	Bag<Type> newb;
	while(tmp!=bag1.item)
	{
		ac=newb.insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
	tmp=bag2.item;
	while(tmp!=bag2.item)
	{
		ac=newb.insert(tmp->value);
		if(ac==0)	break;
		tmp=tmp->nxt;
	}
}

template<class Type>void combine(Type &bag1,Type &bag2,Type &result)
{
	bool ac=1;
	int de=0;
	Item<Type> *tmp=bag1->item->nxt;
	while(tmp!=bag1->item)*/
