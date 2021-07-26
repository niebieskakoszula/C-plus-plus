//https://codeforces.com/contest/1552/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int tests;
	cin >> tests;
	while(tests--){
		int n, result = 0;
		string input, sorted_input;
		cin >> n >> input;
		sorted_input = input;
		
		
		sort(sorted_input.begin(), sorted_input.end());
		for(int i = 0; i < n; i++)
			if(sorted_input[i] != input[i])
				result++;
		
		cout << result << endl;
	}
	return 0;
}
