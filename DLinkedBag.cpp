//#include "stdafx.h"
#include "DLinkedBag.h"

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag(const DLinkedBag<ItemType>& aBag)
{
	itemCount = aBag->itemCount;
	Node<ItemType>* origChainPtr = aBag->headPtr;  // Points to nodes in original chain

	if (origChainPtr == NULL)
		headPtr = NULL;  // Original bag is empty; so is copy
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr; // Last-node pointer
		while (origChainPtr != NULL)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext(); // Advance pointer
		} // end while

		newChainPtr->setNext(NULL); // Flag end of new chain

	} // end if
} // end copy constructor

template<class ItemType>
DLinkedBag<ItemType>::~DLinkedBag()
{
	clear();
}  // end destructor

template<class ItemType>
bool DLinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int DLinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool DLinkedBag<ItemType>::add(const ItemType& newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)        
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  // New node points to chain
	//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

	headPtr = nextNodePtr;          // New node is now first node
	itemCount++;

	return true;
}  // end add

template<class ItemType>
vector<ItemType> DLinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != NULL) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while

	return bagContents;
}  // end toVector

template<class ItemType>
bool DLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
	if (canRemoveItem)
	{
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());

		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;
		nodeToDeletePtr = NULL;

		itemCount--;
	} // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void DLinkedBag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != NULL)
	{
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;

		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is NULL; nodeToDeletePtr is NULL

	itemCount = 0;
}  // end clear

template<class ItemType>
int DLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != NULL) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool DLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != NULL);
}  // end contains

template<class ItemType>
Node<ItemType>* DLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;

	while (!found && (curPtr != NULL))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo