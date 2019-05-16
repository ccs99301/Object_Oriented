#include <iostream>
#include <string>
#include "HuffmanTree.h"
using namespace std;

int main()
{
	HuffmanTree t("Abcdaaaabbbbaaaacceee!@&$()#@%*");
	cout<<t.encode("ceba")<<endl;
	cout<<t.encode("Abcdaaaabbbbaaaacc")<<endl;
	cout<<t.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR")<<endl;
	cout<<t.decode("101011110000111100101111111010111")<<endl;
	cout<<t.decode("1010111100001111001011111110101111")<<endl;
	return 0;
}
