//https://pl.spoj.com/problems/DYZIO2/

#include <bits/stdc++.h>
 
using namespace std;
 
const int  n=1000000;
int values[n+1];
bool S[n+1];
 
int main()
{
    unsigned int N, p, q, x;
    values[1]=0;
    for(int i = 2; i <= n; i++ ) S [ i ] = true;
    p = 2;
    while( p * p <= n ){
        q = p;
        while( p * q <= n ){
            x = p * q;
            while( x <= n ){
                S [ x ] = false;
                x *= p;
            }
        while( !S [ ++q ] );
        }
    while( !S [ ++p ] );
    }
    for(int i = 2; i <= n+1; i++ ){
        if( S [ i ] ) values[i]=values[i-1]+1;
        else values[i]=values[i-1];
    }
 
    cin>>N;
    while(N--){
        int start,endd;
        cin>>start>>endd;
        cout<<values[endd]-values[start-1]<<endl;
    }
    return 0;
}
