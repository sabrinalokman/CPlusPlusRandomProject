#include <iostream>
#include <vector>

using namespace std;


/*
Find The Duplicates
Given two sorted arrays arr1 and arr2 of passport numbers, implement a function findDuplicates that returns an array of all passport numbers that are both in arr1 and arr2. Note that the output array should be sorted in an ascending order.

Let N and M be the lengths of arr1 and arr2, respectively. Solve for two cases and analyze the time & space complexities of your solutions: M ≈ N - the array lengths are approximately the same M ≫ N - arr2 is much bigger than arr1.
*/

vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2) 
{
  int n = arr1.size() - 1;
  vector<int> result;
  for(int i = 0; i < arr2.size(); i++) {
    for (int j = 0; j < arr1.size(); j++) {
      if (arr2[i] > arr1[n]) break;
      else if (arr2[i] == arr1[j]) result.push_back(arr2[i]); 
    }
  }
  return result;
}

int main() {
  vector<int> arr1{1,2,3,5,6,7};
  vector<int> arr2{7,8,9,10,11,12};

  vector<int> solution = findDuplicates(arr1, arr2);

  for(int i = 0; i < solution.size(); i++) {
    std::cout << solution[i] << " ";
  }
  return 0;
}