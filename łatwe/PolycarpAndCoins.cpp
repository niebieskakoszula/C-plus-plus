
//https://codeforces.com/contest/1551/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
	cout.precision(17);
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i){
		int input;
		cin >> input;
		int modulo = input % 3;
		double first, second;
		
		switch(input % 3){
			case 0:
				first = input / 3;
				second = first;
				break;
			case 1:
				input -= 1;
				second = input / 3;
				first = second + 1;
				break;
			case 2:
				input -= 2;
				first = input / 3;
				second = first + 1;
				break;
		}
		
		cout << first << " " << second << endl;
	}
	return 0;
}
