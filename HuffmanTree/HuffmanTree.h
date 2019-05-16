#include <iostream>
#include "Node.h"
using namespace std;

class HuffmanTree
{
	public:
		HuffmanTree(const string&);
		~HuffmanTree();
		string encode(const string&) const;
		string decode(const string&) const;

	private:
		Node* root;
};
