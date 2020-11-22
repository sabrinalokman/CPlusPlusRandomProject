#include <string>
#include <vector>
#include <iostream>

//Leetcode weekly challenge

/*1662. Check If Two std::string Arrays are Equivalent

Given two std::string arrays word1 and word2, return true if the two arrays represent the same std::string, and false otherwise.

A std::string is represented by an array if the array elements concatenated in order forms the std::string.*/

/*Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true*/


class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string str1;
    	std::string str2;

    	for (int i = 0; i < word1.size(); i++) {
    		str1 += word1[i];
    	}
    	for (int i = 0; i < word2.size(); i++) {
    		str2 += word2[i];
    	}

    	//std::cout << str1 << " is it equal to " <<str2 << " " ;

    	if(str1.compare(str2) == 0) 
            return true;
    	else if(str1.compare(str2) != 0) 
            return false;
        
        return 0;
    } 
    
};

int main() {
    Solution s;
    std::vector<std::string> word1 = {"a", "cb"};
    std::vector<std::string> word2 = {"a", "bc"};

    s.arrayStringsAreEqual(word1, word2) == 1 ? std::cout << "true\n" : std::cout << "false\n";

}