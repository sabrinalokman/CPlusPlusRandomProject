#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortKMessedArray(vector<int> arr, int k ) 
{
  // your code goes here
	for (int i = arr.size()-1; i >= 0; i--) {
    	for (int j = 1; j <= k; j++)  {
      		if (arr[i] < arr[i-j] && (i-j) >= 0) {
        		int temp = arr[i];
        		arr[i] = arr[i-j];
        		arr[i-j] = temp;
      }
    }
  }

  for (int i = 0 ; i < arr.size(); i++) {
  	std::cout << arr[i] << " ";
  }
  return arr;
}

int main() {
  vector<int> arr{4, 5, 2, 3, 7, 8, 6, 10, 9};
  int k = 2;
  sortKMessedArray(arr, k);
  return 0;
}