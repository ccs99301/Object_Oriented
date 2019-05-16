#include <iostream>
#include "HuffmanTree.h"
#include "Node.h"
using namespace std;

Node* build(Node* root,char a,char b,int cnt)
{
	InternalNode *tmp1=new InternalNode;
	TerminalNode *tmp2=new TerminalNode,*tmp3=new TerminalNode;
	root=tmp1;
	tmp1->lChild=tmp2;
	tmp1->rChild=tmp3;
	tmp2->value=a;
	tmp3->value=b;
	tmp1->freq=cnt;
	return root;
}

Node* insert(Node* root,char nValue,int cnt)
{
	InternalNode *tmp1=new InternalNode;
	TerminalNode *tmp2=new TerminalNode;
	Node *tmp=tmp1;
	if(root->getFreq()>cnt)
	{
		tmp1->lChild=root;
		tmp1->rChild=tmp2;
		tmp2->value=nValue;
	}
	else
	{
		tmp1->rChild=root;
		tmp1->lChild=tmp2;
		tmp2->value=nValue;
	}
	tmp1->freq=root->getFreq()+cnt;
	return tmp;
}

HuffmanTree::HuffmanTree(const string& s)
{
	int list[96],i,j,len=s.size(),min=95,min2=95;
	list[95]=len+1;
	for(i=0;i<95;i++)
		list[i]=0;
	for(i=0;i<len;i++)
		if(s[i]>=32&&s[i]<=126)
			++list[s[i]-32];
	for(i=0;i<95;i++)
		if(list[i]<list[min]&&list[i]!=0)
			min=i;
	for(i=0;i<95;i++)
		if(list[i]<list[min2]&&list[i]!=0)
			min2=i;
	root=build(root,min+32,min2+32,list[min]+list[min2]);
	list[min]=list[min2]=0;
	for(i=0;i<len-2;i++)
	{
		min=95;
		for(j=0;j<95;j++)
			if(list[j]<list[min]&&list[j]!=0)
				min=j;
		if(min==95)
			break;
		root=insert(root,min+32,list[min]);
		list[min]=0;
	}
}

HuffmanTree::~HuffmanTree()
{
	delete root;
}

string HuffmanTree::encode(const string& s)const
{
	string buf="";
	int len=s.size(),i;
	InternalNode *tmp=(InternalNode*)root;
	for(i=0;i<len;i++)
	{
		while(1)
		{
			if(tmp->getRChild()->getNodeType()==1)
			{
				if(tmp->getLChild()->getValue()==s[i])
				{
					buf+='0';
					tmp=(InternalNode*)root;
					break;
				}
				else
				{
					buf+='1';
					tmp=(InternalNode*)tmp->getRChild();
				}
			}
			else if(tmp->getLChild()->getNodeType()==1)
			{
				if(tmp->getRChild()->getValue()==s[i])
				{
					buf+='1';
					tmp=(InternalNode*)root;
					break;
				}
				else
				{
					buf+='0';
					tmp=(InternalNode*)tmp->getLChild();
				}
			}
			else
			{
				if(tmp->getLChild()->getValue()==s[i])
					buf+='0';
				else if(tmp->getRChild()->getValue()==s[i])
					buf+='1';
				else
				{
					cout<<"error: character "<<s[i]<<" cannot be encoded";
					buf="";
					break;
				}
			}
		}
		if(buf=="")
			break;
	}
	return buf;
}

string HuffmanTree::decode(const string& s)const
{
	string buf="";
	InternalNode *tmp=(InternalNode*)root;
	int i;
	for(i=0;s[i]=='0'||s[i]=='1';i++)
	{
		if(s[i]=='0')
			tmp=(InternalNode*)tmp->getLChild();
		else
			tmp=(InternalNode*)tmp->getRChild();
		if(tmp->getNodeType()==0)
		{
			buf+=tmp->getValue();
			tmp=(InternalNode*)root;
		}
	}
	if(tmp!=root)
	{
		cout<<"error: sequence "<<s<<" cannot be decoded";
		buf="";
	}
	return buf;
}
