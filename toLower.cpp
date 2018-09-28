#include <stdlib.h>
#include <iostream>
#include <string>

class Solution {
	public:
	std::string toLowerCase(std::string str) {
		for(int x = 0; x < str.size(); x++) {
			if( str[x] < 91 && str[x] > 64) {
				str[x] = str[x] + 32;
			}
		}
		return str;
	}

};

int main() {	
	Solution mySolution;
	std::string myString = "Hello";
	mySolution.toLowerCase(myString);
	std::cout << myString;
	return 1;
}
