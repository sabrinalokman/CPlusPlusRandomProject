#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<pair<int,int>> pq;

		unordered_map<int,int> mp;

		for (int i=0; i<n; i++)
			mp[nums[i]]++;

		for(auto x : mp) {
			pq.push({x.second, x.first});
		}

		vector<int> ans;

		while(k--) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;


	}


};

int main() {
	int num, k, temp;
	vector<int> nums;
	Solution s;
	std::cout << "Enter vector size: ";
	std::cin >> num >> k;
	for (int i = 0; i < num; i++) {
		std::cin >> temp;
		nums.push_back(temp);
	}

	vector<int> temporaire = s.topKFrequent(nums, k);
	for (int j = 0; j < temporaire.size(); j++) {
		std::cout << temporaire[j] << " ";
	}
}