//https://codeforces.com/contest/1433/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x, min_moves, first, last;
    cin>>t;
    while(t--){
        cin>>n;
        bool books[n];
        x=0;
        for(int i=0; i<n; i++){
            cin>>books[i];
            if(books[i]==1)x++;
        }
        if(x==1 || x==n) cout<<0<<endl;
        else{
            min_moves=0;
            for(int i=0; i<n; i++){
                if(books[i]==1){
                    first=i;
                    break;
                }
            }
            for(int i=n-1; i>=0; i--){
                if(books[i]==1){
                    last=i;
                    break;
                }
            }
            for(int i=first+1; i<last; i++){
                if(books[i]==0){
                    min_moves++;
                }
            }
            cout<<min_moves<<endl;
        }
    }
    return 0;
}
