#include <iostream>
using namespace std;

class IntSet
{
	public:
		IntSet();
		IntSet(int);
		bool isEmpty() const;
		int size() const;
		void setPrint() const;
		void setAdd(int);	//add new element
		IntSet setUnion(const IntSet&);
		IntSet setIntersection(const IntSet&);
		IntSet relativeComplement(const IntSet&);
		IntSet symmetricDifference(const IntSet&);
		bool isEqualTo(const IntSet&) const;

	private:
		int num[1000];
};
