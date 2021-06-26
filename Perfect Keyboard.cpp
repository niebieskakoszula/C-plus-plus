//http://codeforces.com/contest/1303/problem/C

#include <bits/stdc++.h>
using namespace std;


int neighbours[26][26];
int neighbours_count[26];

int main() {
    int tests;
    string input;
    cin >> tests;

    for(int i = 0; i < tests; ++i) {
        cin >> input;

        //Creating array of neighbouring characters
        memset(neighbours, 0, sizeof neighbours);
        memset(neighbours_count, 0, sizeof neighbours_count);
        for(int j = 1; j < (int) input.length(); ++j) {
			if (input[j - 1] == input[j]) continue;
            neighbours[input[j - 1]-'a'][input[j]-'a'] = 1;
            neighbours[input[j]-'a'][input[j - 1]-'a'] = 1;
        }


        //Checking if it's possible
        bool is_valid = true;
        int end_count = 0, current_node = 0;
        for(int x = 0; x < 26 && is_valid; ++x) {
            for(int y = 0; y < 26; ++y) {
                if(neighbours[x][y]) {
                    neighbours_count[x]++;
                }
            }

            if(neighbours_count[x] >= 3) {
                is_valid = false;
                break;
            } else if (neighbours_count[x] == 1) {
				//cerr << x << " ";
                end_count++;
                current_node = x;
            }
        }
        int zero_count = 0;
        for (int j = 0; j < 26; j++) {
			if (neighbours_count[j] == 0) zero_count++;
		}

		if (zero_count == 26) {
			cout << "YES" << "\n";
			for (char j = 'a'; j <= 'z'; j++) {
				cout << j;
			}
			cout << "\n";
			continue;
		}

        if (end_count != 2 || !is_valid) {
            cout<<"NO"<<endl;
            continue;
        }

        //If it's possible create keyboard
        string result = "";
        result += (char) ('a' + current_node);
		memset(neighbours_count, 0, sizeof neighbours_count);
		neighbours_count[current_node] = 1;

        while(true) {
            int next_node = -1;
            for (int j = 0; j < 26; j++) {
                if (neighbours[current_node][j] == 1 && neighbours_count[j] != 1) {
					neighbours_count[j] = 1;
                    result += (char) (j + 'a');
                    next_node = j;
                    break;
                }
            }
            if (next_node == -1) break;

            current_node = next_node;
        }

        cout << "YES" << "\n";
        for (int i = 0; i < 26; i++) {
			if (neighbours_count[i] == 1) continue;
			result += (char) (i + 'a');
		}
		cout << result << "\n";
    }
    return 0;
}
