#include <iostream>
#include <vector>

/*Shifted Array Search
A sorted array of distinct integers shiftArr is shifted to the left by an unknown offset and you don’t have a pre-shifted copy of it. For instance, the sequence 1, 2, 3, 4, 5 becomes 3, 4, 5, 1, 2, after shifting it twice to the left.

Given shiftArr and an integer num, implement a function shiftedArrSearch that finds and returns the index of num in shiftArr. If num isn’t in shiftArr, return -1. Assume that the offset can be any value between 0 and arr.length - 1.

Explain your solution and analyze its time and space complexities.

Binary search solution
Time = O(log n)
Space = O(1)

*/

using namespace std;

int shiftedArrSearch( const vector<int>& shiftArr, int num ) 
{
  int start = 0, end = shiftArr.size()-1;
  
  while(start <= end) {
    int mid = (start + end) / 2;
    if(shiftArr[mid] == num) {
      return mid;
    } 
    
    if(shiftArr[mid] > shiftArr[start]) {
      if (shiftArr[start] <= num && num <= shiftArr[mid]) {
        end = mid - 1;
      } else
        start = mid + 1;
    } else {
      if (shiftArr[mid] <= num && num <= shiftArr[end]) {
        start = mid + 1;
      } else
        end = mid - 1;
    }
  } return -1;
}


int main() {
  std::vector<int> A {9, 12, 17, 2, 4, 5};
  int target = 2;

  std::cout << shiftedArrSearch(A, target);

  return 0;
}