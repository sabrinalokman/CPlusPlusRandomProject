//Can be further optimized
/* steps in this solution
1) determine period location per string
2) delimited the string
3) check if IP is valid by checking if digit has leading zero
4) check if IP is valid by checking if digit is between 0-255

//optimized solution
1) check if number is valid while determining the period location
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> single(4);
vector<int> point(3);

void printVector(vector<string> a) {
	for (auto a : a) {
		cout << a << endl;
	}
}

bool isValid (int digit) {
	if(digit < 0 || digit > 255) 
			return false;
	return true;
}

bool createIp(vector<int>& point, string& str) {
	int N = str.length();
	
	if((str.substr(0, point[0] - 0)[0] == '0' 
									&& (point[0] - 0) > 1) ||
		(str.substr(point[0], point[1] - point[0])[0] == '0' 
		 									&& (point[1] - point[0]) > 1) ||
		(str.substr(point[1], point[2] - point[1])[0] == '0' 
		 									&& (point[2] - point[1]) > 1) ||
		(str.substr(point[2], N - point[2])[0] == '0' 
		 									&& (N - point[2]) > 1)) 
		return false;
	else {
		int prev = 0;
		for(int i = 0; i < single.size(); i++) {
			single[i] = stoi(str.substr(prev,point[i] - prev));
			prev = point[i];
			if(!isValid(single[i])) return false;
		}	
	}
	return true;
}

void storeIp(vector<string> &solution) {
	string temp;
	for(auto a : single) {
		temp += to_string(a) + ".";
	} temp.pop_back();
	
	solution.push_back(temp);
}

vector<string> validIPAddresses(string str) {
	vector<string> solution;
  if(str.length() < 4 || str.length() > 12) { return {}; }	
	int N = str.length();
	
	for (int i = 1; i < 4; i++) {
		for(int j = 1; j < 4; j++) {
			for(int k = 0; k < 3; k++) {
				point[0] = i;
				point[1] = i + j;
				point[2] = (N - (i+j) - 1)/2 + i + j + k;
				
				if(point[2] == i + j || point[2] >= N) 
					continue; 
				else if(createIp(point, str)) 
						storeIp(solution);
			}
		}
	}
	
	return solution;
}

int main() {
	string str = "1921680";
	printVector(validIPAddresses(str));
	return 0;
}
