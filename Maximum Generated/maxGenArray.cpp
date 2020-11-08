#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*You are given an integer n. An array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.*/

class Solution {
public:
	int getMaximumGenerated(int n) {
		int nums[n+1];
		if (n < 1) {
			nums[0] = 0;
		}
		if (n >= 1) {
			nums[0] = 0;
			nums[1] = 1;
		}
		for(int i = 1; i <= n; i++) {

			if(2*i>= 2 && 2*i <=n) {
				nums[2*i] = nums[i];
			}
			if (2*i+1>= 2 && 2*i+1 <=n) {
				nums[2*i+1] = nums[i] + nums[i+1];
			}

		}

		// for (int j = 0; j < sizeof(nums)/sizeof(nums[0]); j++) {
		// 	std::cout << nums[j] << " ";
		// }
		
		return *std::max_element(nums, nums+n+1);
        
    }

};

int main() {
	int N;
	std::cout << "Enter N: ";
	std::cin >> N;
	Solution s;
	std::cout << s.getMaximumGenerated(N);

}