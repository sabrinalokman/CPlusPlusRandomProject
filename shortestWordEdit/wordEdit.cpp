#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


/*Shortest Word Edit Path
Given two words source and target, and a list of words words, find the length of the shortest series of edits that transforms source to target.

Each edit must change exactly one letter at a time, and each intermediate word (and the final target word) must exist in words.

If the task is impossible, return -1.

Examples:

source = "bit", target = "dog"
words = ["but", "put", "big", "pot", "pog", "dog", "lot"]

output: 5
explanation: bit -> but -> put -> pot -> pog -> dog has 5 transitions.*/

//Breadth First Search

int check(string source, string word) {
  if(source > word) 
    swap(word, source);
  int count = 0;

  for(int i = 0; i < source.size(); i++){
     if(source[i] != word[i])
      count++;
  }

  if(source.size() != word.size()) 
    return 2;

  return count;
}

int shortestWordEditPath(const string& source, const string& target, const vector<string>& words)
{
  if(source == target) 
    return 0;

  map<string, int> visit;
  map<string, int> mp;
  queue<string> q;

  q.push(source);

  mp[source] = 0;
  visit[source] = 1;
  
  while(!q.empty()){
    string src = q.front();
    q.pop();
    for(int i = 0; i < words.size(); i++) {   // src = a,b,c,d,e,f,g,h,i,j
       string a = words[i];
       if(visit[a] == 0){
          if(check(src, a) == 1){
            q.push(a);
            mp[a] = mp[src] + 1;
            visit[a] = 1;
          }
       }
    }
  }
  if(mp[target] == 0) 
    return -1;
  else 
    return mp[target];
}

int main() 
{ 
  string source = "bit";
  string target = "dog";
  vector<string> words {"but","put","big","pot","pog","dog","lot"};
  std::cout << shortestWordEditPath(source, target, words) << "\n";
 
  return shortestWordEditPath(source, target, words);
  
}

/* 
Input:"bit", "dog", ["but","put","big","pot","pog","dog","lot"]
Expected: 5

Input: "no", "go", ["to"]
Expected: -1

Input: "bit", "pog", ["but","put","big","pot","pog","pig","dog","lot"]
Expected: 3

Input: "aa", "bb", ["ab","bb"]
Expected: 2

Input: "abc", "ab", ["abc","ab"]
Expected: -1

Input: "aa", "bbb", ["ab","bb"]
Expected: -1
*/