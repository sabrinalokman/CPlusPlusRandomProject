#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
K-Messed Array Sort
Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function sortKMessedArray that sorts arr. For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2

output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
*/

vector<int> sortKMessedArray(vector<int> arr, int k ) 
{
  // your code goes here
	for (int j = k; j > 0; j--){
    	for (int i = arr.size()-1; i >= 0; i--){
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

  std::cout << "\n";
  return arr;
}

int main() {
  vector<int> arr{4, 5, 2, 3, 7, 8, 6, 10, 9};
  int k = 2;
  sortKMessedArray(arr, k);
  
  vector<int> arr1{1,0}; k = 1;
  sortKMessedArray(arr1, k);

  vector<int> arr2{1,0,3,2}; k = 1;
  sortKMessedArray(arr2, k);

  vector<int> arr3{1,0,3,2,4,5,7,6,8}; k = 1;
  sortKMessedArray(arr3, k);

  vector<int> arr4{1,2,3,4,5,6,7,8,9,10}; k = 2;
  sortKMessedArray(arr4, k);

  vector<int> arr5{6,1,4,11,2,0,3,7,10,5,8,9}; k = 6;
  sortKMessedArray(arr5, k);



  return 0;
}