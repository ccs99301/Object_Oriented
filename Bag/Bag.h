#pragma once
#include <iostream>
using namespace std;

template<class Type>class Bag;
template<class Type>void combine(Bag<Type>&,Bag<Type>&,Bag<Type>&);
template<class Type>void subtract(Bag<Type>&,Bag<Type>&,Bag<Type>&);

template<class Type>
class Item
{
	public:
		Item();
		Item(Type);

	private:
		bool dummy;
		Type value;
		Item<Type> *nxt;
	 	Item<Type> *pre;

	template<class Btype>friend class Bag;
	template<class Ftype>friend void combine(Bag<Ftype>&,Bag<Ftype>&,Bag<Ftype>&);
	template<class Ftype>friend void subtract(Bag<Ftype>&,Bag<Ftype>&,Bag<Ftype>&);
};

template<class Type>
class Bag
{
	public:
		Bag();
		~Bag();
		Bag(const Bag&);
		Bag& operator=(const Bag&);
		bool empty() const;
		int size() const;
		int uniqueSize() const;
		bool insert(const Type&);
		int erase(const Type&);
		int eraseAll(const Type&);
		bool contains(const Type&);
		int count(const Type&);
		void start();
		void next();
		bool ended() const;
		const Type currentValue() const;
		int currentCount() const;
	
	private:
		Item<Type> *item;
		Item<Type> *finger;
	
	template<class Ftype>friend void combine(Bag<Ftype>&,Bag<Ftype>&,Bag<Ftype>&);
	template<class Ftype>friend void subtract(Bag<Ftype>&,Bag<Ftype>&,Bag<Ftype>&);
};

