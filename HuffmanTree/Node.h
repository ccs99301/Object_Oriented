#pragma once
#include <iostream>
using namespace std;

class Node
{
	public:
		int getFreq();
		virtual int getNodeType();
		virtual char getValue();
		virtual Node* getLChild();
		virtual Node* getRChild();
	protected:
		int freq;
};

Node* build(Node*,char,char,int);
Node* insert(Node*,char,int);

class InternalNode: public Node
{
	public:
		int getNodeType();
		Node* getLChild();
		Node* getRChild();
		char getValue();	//none
	private:
		Node* lChild;
		Node* rChild;
	friend Node* build(Node*,char,char,int);
	friend Node* insert(Node*,char,int);
};

class TerminalNode: public Node
{
	public:
		int getNodeType();
		Node* getLChild();	//none
		Node* getRChild();	//none
		char getValue();
	private:
		char value;
	friend Node* build(Node*,char,char,int);
	friend Node* insert(Node*,char,int);
};

