#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    	int solution = 0;
    	map<int, int, greater<int>> hashmap;

        for(int i=0; i < boxTypes.size(); i++) {
    		hashmap[boxTypes[i][1]] = boxTypes[i][0];
        }
        for(auto a : hashmap) {
            int x = std::min(a.second, truckSize);
            solution += (x * a.first);
            truckSize -= x;
            if(!truckSize) break;

        }
        return solution;
    }
    
};

int main() {
	Solution s;
	vector<vector<int>> boxTypes {
		{5,10}, 
		{2,5}, 
		{4,7},
        {3,9}
	};

	int truckSize = 10;

	cout << s.maximumUnits(boxTypes, truckSize) << endl;
}