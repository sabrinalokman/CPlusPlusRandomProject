#include <iostream>
#include <string>

using namespace std;

/*
Decrypt Message

Their messages consist of lowercase latin letters only, and every word is encrypted separately as follows:

Convert every letter to its ASCII value. Add 1 to the first letter, and then for every letter from the second one to the last one, add the value of the previous letter. Subtract 26 from every letter until it is in the range of lowercase letters a-z in ASCII. Convert the values back to letters.

input:  word = "dnotq"
output: "crime"

input:  word = "flgxswdliefy"
output: "encyclopedia"
*/

/*
1) Iterate through the word
2) for the first letter, get the ASCII value - 1, add that to myDescript string
3) keep track of prev value
4) while the ASCII value of that letter - prev value == less than 97, keep adding 26
5) add that to myDescript string and keep track of the prev value of the 2nd element onwards
6) 

*/

string decrypt( const string& word ) 
{ 
    std::string myDecrypt;
    int prev;
    int letter;
  
  for (int i = 0; i < word.size(); i++) {
    if (i == 0) {
      letter = int(word.at(i));
      myDecrypt += (char(letter - 1));
      prev = letter;
    }
    else {
      letter = int(word.at(i));
      while(letter - prev < 97) { //97 is letter a
        letter += 26;
      }
      myDecrypt += (char(letter-prev));
      prev = letter;
    }
  }
  return myDecrypt;
}

int main() {
  string myStr {"flgxswdliefy"};
  std::cout << decrypt(myStr);

  return 0;
}