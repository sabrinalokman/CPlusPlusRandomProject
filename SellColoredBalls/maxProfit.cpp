#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;

/*
You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.
*/

//TO DO: SOLVE ISSUE WITH CASE 4 TLE

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        unsigned long long sum = 0, tempMax, tempIter;
        vector<int>::iterator result;
        unsigned long long fix = 1000000007;
        while(orders--) {
        	result = std::max_element(inventory.begin(), inventory.end());
        	sum += *std::max_element(inventory.begin(), inventory.end());

        	// I need the iterator for that max element
        	tempIter = std::distance(inventory.begin(), result);
        	tempMax = inventory[tempIter];
        	inventory[tempIter] = tempMax - 1; 
        }

        int sumOpt = sum % fix;

        return sumOpt;
    }
};


int main() {
	vector<int> i1{2,5};
	int o1 = 4;
	Solution s;
	std::cout << s.maxProfit(i1, o1) << " ";

	vector<int> i2{3,5};
	int o2 = 6;
	std::cout << s.maxProfit(i2, o2)<< " ";

	vector<int> i3{2,8,4,10,6};
	int o3 = 20;
	std::cout << s.maxProfit(i3, o3)<< " ";

	vector<int> i4{1000000000};
	int o4 = 1000000000;
	std::cout << s.maxProfit(i4, o4)<< " ";

}