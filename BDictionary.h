
#ifndef BDICTIONARY_H
#define BDICTIONARY_H

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"
#include <memory>

template <typename Key, typename E>
class BDictionary :  public Dictionary<Key, E> {
public:

	//constructor
	BDictionary<Key, E> (int size = defaultSize) {
		bArray = new ABag<KVpair<Key, E>>(size); //create a new instantiation of default size 
	}

	//destructor
	~BDictionary() {
		delete bArray;
	}

	void clear(){
		bArray->emptyBag(); // Reinitialize dictionary
	}
	
	bool insert(const Key& k, const E& e) {
		std::unique_ptr<KVpair<Key, E>> temp = std::make_unique<KVpair<Key, E>>(k, e);
		if (bArray->addItem(*temp) == true) 
		{
			return true; // Return true if insert is successful and false otherwise
		}
		else {
			return false;
		}
	}

	bool remove(const Key& k, E& rtnVal) {
		std::unique_ptr<KVpair<Key, E>> temp = std::make_unique<KVpair<Key, E>>(k, rtnVal);
		if (bArray->remove(*temp) == true) {
			rtnVal = temp->value();
			return true;
		} else {
			return false;
		}
	}

	bool removeAny(E& returnValue) {
		std::unique_ptr<KVpair<Key, E>> temp = std::make_unique<KVpair<Key, E>>();
		if (bArray->removeTop(*temp) == true) {
			returnValue = temp->value();
			return true;
		} else {
			return false;
		}
	}

	bool find(const Key& k, E& returnValue) const {
		std::unique_ptr<KVpair<Key, E>> temp = std::make_unique<KVpair<Key, E>>(k, returnValue);
		if (bArray->find(*temp) == true) {
			returnValue = temp->value();
			return true;
		} else {
			return false;
		}
	}

	int size() {
		return bArray->size();
	}

private:
	ABag<KVpair<Key, E>>*bArray;
};

#endif