//https://codeforces.com/contest/1454/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests, length ;
    cin>>tests;
    while(tests--){
        cin>>length ;
        for(int i = 0; i < length ; i++){
            cout<<((i + 1) % length  ) + 1 <<" ";
        }
        cout<<endl;
    }
    return 0;
}
