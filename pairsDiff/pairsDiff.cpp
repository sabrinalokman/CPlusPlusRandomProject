#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
Pairs with Specific Difference
Given an array arr of distinct integers and a nonnegative integer k, write a function findPairsWithGivenDifference that returns an array of all pairs [x,y] in arr, such that x - y = k. If no such pairs exist, return an empty array.

Note: the order of the pairs in the output array should maintain the order of the y element in the original array.
*/

vector<vector<int>> findPairsWithGivenDifference( const vector<int>& arr, int k) 
{
  
  vector<vector<int>> result;
  map<int, int> mp;

  
  for(auto a : arr) { 
    mp[a] = a - k; 
  }

  for(auto b : arr) {
    for(auto c : mp) {
      if(b == c.second) {
        result.push_back({c.first, c.second});
      } 
    }
  }

  return result;
}

int main() {
  vector<int> arr {0, -1, -2, 2, 1};
  int k = 1;
  
  vector<vector<int>> res = findPairsWithGivenDifference(arr, k);
  
  for(int i = 0; i < res.size(); i++)  {
    for(int j = 0; j < res[i].size(); j++ ) {
      std::cout << res[i][j] << " ";
    } std::cout << "\n";
    
  }
  return 0;
}