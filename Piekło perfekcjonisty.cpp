#include <bits/stdc++.h>

using namespace std;

vector<string> combinations;

void preprocessing(){
	string pattern = "1234";
	int index = 0;
	do{
		combinations.push_back("");
    	for(int i = 0; i < 25000; i++){
    		combinations[index] += pattern;
		}
		index++;
	}while(next_permutation(pattern.begin(), pattern.end()));
}

int main(){
    int t;
    string input;
    
    preprocessing();
    
    cin >> t;
    while(t--){
        cin >> input;
        
        int best_result = input.size(), best_plan, changes;
        for(int i = 0; i < 24; i++){
        	changes = input.size();
        	for(int j = 0; j < input.size(); j++){
        		if(input[j] == combinations[i][j])
        			changes--;
			}
			if(changes < best_result){
				best_plan = i;
				best_result = changes;
			}	
		}
        
        string result = combinations[best_plan].substr(0, input.size());
        cout << result << endl;
    }
    return 0;
}
