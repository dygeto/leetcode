#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
	Solution () {

	}

    int findLUSlength(std::vector<std::string>& strs) {
        std::vector<int> LUScounter;
        std::unordered_map<int,bool> isUnique;

        for(int x = 0; x < strs.size(); x++) {    
                LUScounter.push_back(strs[x].size());
		//std::cout << "X: " << x << "Count: " << LUScounter[x] << "\n";
            //for(int y = x; y < strs.size(); y++) {
             //   if (strs[x] != strs[y]) {
             //       isUnique[x] = true;
              //      isUnique[y] = true;
              //  }
                
                
          //  }
        }
	//int y = LUScounter.size();
	//std::cout << y;
        // check edge case if no unique subsequences (all strings equal)
        int max = 0;


        for(int x = 0; x < LUScounter.size(); x++) {
            if(LUScounter[x] > max)
                max = LUScounter[x];
        }
        return max;
            
    }
};


int main() {
	Solution mySolution;
	std::vector<std::string> strs;
	strs.push_back("aaa");
	strs.push_back("aaaaa");
	strs.push_back("aaa");
	strs.push_back("aaa");
	strs.push_back("aaaaaaaaaaaa");
	strs.push_back("a");
	strs.push_back("b");
	strs.push_back("c");

	//int y = strs.size();
	int x = mySolution.findLUSlength(strs);
	
	std::cout << x;
	return 1;
}
