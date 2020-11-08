#include <iostream>
#include <vector>
#include <map>
#include <string>

/*
Minimum deletion to make character unique
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/

class Solution {
  public:
    int minimumDeletion(std::string s) {
      std::vector<int> c(26,0); // hash map, a vector with 26 element (all of the alphabet)
     
      for(auto x : s)
        c[x - 'a']++; //element - a because a is the starting element
      
      std::map<int,int> myMap;
      int result = 0;
      
      for(int i=0; i < 26; i++) {
        int init = c[i];
        if (init == 0) 
          continue;
        if (myMap.find(init) != myMap.end()) {
          result++;
          c[i]--;
          i--;
        }
        else 
          myMap[init] = 1;
      }
      return result;
    }
  
  
};

int main() {
  Solution s;
  std::string x = "aab";
  std::cout << s.minimumDeletion(x) << "\n";
  //answer 0
  
  std::string y = "aaabbbcc";
  std::cout << s.minimumDeletion(y) << "\n";
  //answer 2
  
  std::string z = "ceabaacb";
  std::cout << s.minimumDeletion(z) << "\n";
  //answer 2
}