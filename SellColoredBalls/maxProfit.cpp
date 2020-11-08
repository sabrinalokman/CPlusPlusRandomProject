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
/*
Greedy solution
Get the maximum amount in inventory
add that to sum
reduce the maximum amount by 1
iterate through orders
return sum
*/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        unsigned long long sum = 0, tempMax, tempIndex;
        vector<int>::iterator result;
        unsigned long long fix = pow(10.0, 9.0) + 7;
        
        while(orders--) {
        	sum += *std::max_element(inventory.begin(), inventory.end());
        	// I need the index for that max element
        	// we do this ebcause we want to substract the element by 1
        	tempIndex = std::distance(inventory.begin(), std::max_element(inventory.begin(), inventory.end()));
        	tempMax = inventory[tempIndex]; //store the old maximum amount
        	inventory[tempIndex] = tempMax - 1;  //reduce the old value by 1 
        }

        int sumOpt = sum % fix; // try to fix the TLE

        return sumOpt;
    }
};


int main() {
	vector<int> i1{2,5};
	// sell 5 4 3 2
	int o1 = 4;
	Solution s;
	std::cout << s.maxProfit(i1, o1) << " ";
	//answer 14

	vector<int> i2{3,5};
	// sell 5 4 3 3 2 2
	int o2 = 6;
	std::cout << s.maxProfit(i2, o2)<< " ";
	//answer 19

	vector<int> i3{2,8,4,10,6};
	int o3 = 20;
	std::cout << s.maxProfit(i3, o3)<< " ";
	//answer 110

	// vector<int> i4{1000000000};
	// int o4 = 1000000000;
	// std::cout << s.maxProfit(i4, o4)<< " ";
	//answer 21

}