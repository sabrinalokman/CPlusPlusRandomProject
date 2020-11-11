#include <iostream>
#include <string>
#include<stack> 

/*
Bracket Match
A string of brackets is considered correctly matched if every opening bracket in the string can be paired up with a later closing bracket, and vice versa. For instance, “(())()” is correctly matched, whereas “)(“ and “((” aren’t. For instance, “((” could become correctly matched by adding two closing brackets at the end, so you’d return 2.

Given a string that consists of brackets, write a function bracketMatch that takes a bracket string as an input and returns the minimum number of brackets you’d need to add to the input in order to make it correctly matched.

Explain the correctness of your code, and analyze its time and space complexities.

*/


using namespace std;


int bracketMatch(const string &text ) {
  std::stack<char> mystack;
  int count = 0;

  for(const char& i : text) {

    if (i == '(') { 
      mystack.push(i);
      count++;
    }
    else if (i == ')') {
      if(mystack.empty()) {
        count++;
      }
      else if (!mystack.empty()) {
      mystack.pop();
      count--;
      }
    }
  }
  return count;
}


int main() {
  string s1 ("())(");
  std::cout << bracketMatch(s1) << "\n ";
  return 0;
}

/*Test case
)
(
(())
(()
())(
))))
)(
()()()()()
*/