#include <iostream>
#include "Node.h"
using namespace std;

int Node::getFreq()
{
	return freq;
}

int Node::getNodeType()
{
	return -1;
}

char Node::getValue()
{
	return '\0';
}

Node* Node::getLChild()
{
	return NULL;
}

Node* Node::getRChild()
{
	return NULL;
}

int InternalNode::getNodeType()
{
	return 1;
}

Node* InternalNode::getLChild()
{
	return lChild;
}

Node* InternalNode::getRChild()
{
	return rChild;
}

char InternalNode::getValue()
{
	cout<<"Iternal node has no value"<<endl;
	return '\0';
}

int TerminalNode::getNodeType()
{
	return 0;
}

Node* TerminalNode::getLChild()
{
	cout<<"Terminal node has no child"<<endl;
	return NULL;
}

Node* TerminalNode::getRChild()
{
	cout<<"Terminal node has no child"<<endl;
	return NULL;
}

char TerminalNode::getValue()
{
	return value;
}
