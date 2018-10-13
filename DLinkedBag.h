#ifndef _LINKEDBAG
#define _LINKEDBAG
#include "BagInterface.h"
#include "Node.cpp"
using namespace std;

template<class ItemType>
class DLinkedBag : public BagInterface<ItemType>
{

private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount;           // Current count of bag items

	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
	DLinkedBag();
	DLinkedBag(const DLinkedBag<ItemType>& aBag); // Copy constructor
	virtual ~DLinkedBag();                       // Destructor should be virtual
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;

};


#endif