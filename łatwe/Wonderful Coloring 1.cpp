//https://codeforces.com/contest/1551/problem/B1

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int tests;
	cin >> tests;
	while(tests--){
		string input;
		cin >> input;
		
		map<char, int> test;
		for(int i = 0; i < input.length(); i++)
			test[input[i]]++;
		
		int  result = 0;
		for(auto x : test){
			if(x.second > 2)
				result += 2;
			else
				result += x.second;
		}
		result /= 2;
		cout << result << endl;
	}
	return 0;
}
