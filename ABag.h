

#ifndef ABAG_H
#define ABAG_H

#include <String>
#include "bagADT.h"
#include "kvpair.h"
#include <memory>

const size_t BAG = 10;
const size_t ZERO = 0;

template <typename E>
class ABag : public Bag<E> {
public:

	ABag(size_t size = BAG) {
		maxSize = size;
		listSize = ZERO;
		bArray = new E[maxSize];
	}
	~ABag() {
		delete[] bArray;
	}

	bool addItem(const E& item) { 
			if (listSize == maxSize) {
					return false;
			} else {
				bArray[listSize++] = item;
				return true;
			}
	}

	bool remove(E& item) {
		
		if (listSize == ZERO) {
			std::cout << "\nList is Empty\n";
			return false;
		} else {
			for (int i = 0; i < listSize; i++) {
				if (bArray[i] == item) {
					item = bArray[i];
					for (int k = i + 1; k < listSize; k++) {
						bArray[i] = bArray[k];
					}
					listSize--;
					std::cout << "\nItem found and removed\n";
					return true;
				} else {
					std::cout << "\n**Item not found**\n";
					return false;
				}
			}
		}
	}


	bool removeTop(E& returnValue) {
		if (listSize == ZERO) {
			std::cout << "\nList is Empty\n";
			return false;
		} else {
			returnValue = bArray[listSize-1];
			listSize--;
			return true;
		}
		return true;
	}

	
	bool find(E& returnValue) const {
		
		for (int i = 0; i < listSize; i++) {
			if (bArray[i] == returnValue) {
				returnValue = bArray[i];
				cout << "Item found\n";
				return true;
			}
		}
		cout << "Item not found";
		return false;
	}


	bool inspectTop(E& item) const {
		int top = listSize - 1;
		if (top < 0) {
			return false;
		} else {
			item = bArray[top];
			cout << item.key() << "\n" << item.value() << "\n";
			return true;
		}
	}

	// empties the bag
	void emptyBag() {
		listSize = 0;
	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend) {
		return addItem(addend);
	}

	// get the number of items in the bag
	int size() const {
		return listSize;
	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const {
		return maxSize;
	}

	private:
		int maxSize;
		int listSize;
		E* bArray;
};


#endif 