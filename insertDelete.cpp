#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <stdlib.h>

class RandomizedSet {
	private:
	std::vector<int> mySet;
	std::unordered_map<int,int> myMap;

	public:
	RandomizedSet() {}

	bool insert(int val) {
		if(myMap.count(val))
			return false;
		mySet.push_back(val);
		myMap[val] = mySet.size()-1;
		return true;
	}
	
	// when item is deleted from set, the keys are all of by 1
	//	(the key specifies the position of the value in the set)
	bool remove(int val) {
		if(!myMap.count(val))
			return false;
		//int position = myMap[val];
		//mySet.erase(mySet.begin()+position);
		//myMap.erase(val);

		int last = mySet.back(); // last position in set
		myMap[last] = myMap[val];
		mySet[myMap[val]] = last;

		mySet.pop_back();
		myMap.erase(val);

		return true;
	}

	int getRandom() {
		int val = rand() %mySet.size();
		return mySet[val];
	}

	void printSet() {
		for (int x = 0; x < mySet.size(); x++)
			printf("Value:%d \n", mySet[x]);
		}
};


int main() {
	RandomizedSet rs;

	for (int x = 0; x < 100; x++) 
		rs.insert(x);

	rs.remove(5);
	rs.remove(8);
	rs.remove(15);
	rs.remove(25);

	rs.printSet();
	
	return 1;
	}
