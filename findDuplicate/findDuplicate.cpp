#include <iostream>
#include <vector>

using namespace std;

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