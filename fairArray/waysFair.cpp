#include <iostream>
#include <vector>

/*1664. You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.*/

class Solution {
public:

    int waysToMakeFair(std::vector<int>& A) {
    	int count = 0, evenPrefix = 0, evenSuffix = 0, oddPrefix = 0, oddSuffix = 0;

        for (int i = 0; i < A.size(); ++i) {
        	if( i % 2 == 0) evenSuffix += A[i];
        	else oddSuffix += A[i];
        }

        for (int i = 0; i < A.size(); ++i) {
        	if( i % 2 == 0) evenSuffix -= A[i];
        	else oddSuffix -= A[i];

        	count += (evenPrefix + oddSuffix == oddPrefix + evenSuffix);
        	if( i % 2 == 0) evenPrefix += A[i];
        	else oddPrefix += A[i];
        }
        	
        return count;
    }
};

int main () {
	Solution s;

	std::vector<int> nums {1, 2, 3};

	std::cout << s.waysToMakeFair(nums);
}