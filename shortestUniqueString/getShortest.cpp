#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string getShortestUniqueSubstring( const vector<char>& arr, const string &s ) 
{
  std::string t(arr.begin(), arr.end());
  
  unordered_map<char, int> counter;
  for (char c: t) 
    counter[c]++;
        
  int min_len = INT32_MAX;
  int min_idx = -1;
  int left = 0, right = 0;
  int remaining = t.length();
        
  while (right < s.size()) {
    if (counter[s[right]] > 0) 
      remaining--;
    
    counter[s[right]]--;
    right++;
    while (remaining == 0) {
      if (right-left < min_len) {
        min_idx = left;
        min_len = right-left;
      }
      if (counter[s[left]] >= 0) 
        remaining++;
      
      counter[s[left]]++;
      left++;
    }
  }
  return min_len < INT32_MAX ? s.substr(min_idx, min_len):"";
  
}



int main() {

  std::cout << "Test Case 1\nAnswer: ";
  vector<char> arr1{'x', 'y', 'z'};
  string str1 = "xyyzyzyx";
  std::cout << getShortestUniqueSubstring(arr1, str1);
  std::cout << "\nExpected: zyx\n\n";

  std::cout << "Test Case 2\nAnswer: ";
  vector<char> arr2{'A'};
  string str2 = "";
  std::cout << getShortestUniqueSubstring(arr2, str2);
  std::cout << "\nExpected: " "\n\n";

  std::cout << "Test Case 3\nAnswer: ";
  vector<char> arr3{'A'};
  string str3 = "B";
  std::cout << getShortestUniqueSubstring(arr3, str3);
  std::cout << "\nExpected: " "\n\n";

  std::cout << "Test Case 4\nAnswer: ";
  vector<char> arr4{'A'};
  string str4 = "A";
  std::cout << getShortestUniqueSubstring(arr4, str4);
  std::cout << "\nExpected: A\n\n";

  std::cout << "Test Case 5\nAnswer: ";
  vector<char> arr5{'A','B', 'C'};
  string str5 = "ADOBECODEBANCDDD";
  std::cout << getShortestUniqueSubstring(arr5, str5);
  std::cout << "\nExpected: BANC\n\n";

  std::cout << "Test Case 6\nAnswer: ";
  vector<char> arr6{'A','B','C','E','K','I'};
  string str6 = "KADOBECODEBANCDDDEI";
  std::cout << getShortestUniqueSubstring(arr6, str6);
  std::cout << "\nExpected: KADOBECODEBANCDDDEI\n\n";

  std::cout << "Test Case 7\nAnswer: ";
  vector<char> arr7{'x', 'y', 'z', 'r'};
  string str7 = "xyyzyzyx";
  std::cout << getShortestUniqueSubstring(arr7, str7);
  std::cout << "\nExpected: " "\n\n";

  return 0;
}