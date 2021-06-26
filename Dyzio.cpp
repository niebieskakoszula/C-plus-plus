//https://pl.spoj.com/problems/DYZIO2/

#include <bits/stdc++.h>

using namespace std;

const int  range = 1000000;
int values[range + 1];
bool S[range + 1];

void Generate_Primes(){
    int p, q, x;
    values[1]=0;

    for(int i = 2; i <= range; i++ ) S [ i ] = true;
    p = 2;
    while( p * p <= range ){
        q = p;
        while( p * q <= range ){
            x = p * q;
            while( x <= range ){
                S [ x ] = false;
                x *= p;
            }
        while( !S [ ++q ] );
        }
    while( !S [ ++p ] );
    }
    for(int i = 2; i <= range + 1; i++ ){
        if(S[i]) values[i] = values[i - 1] + 1;
        else values[i] = values[i - 1];
    }
}

int main()
{
    Generate_Primes();
    int tests;
    cin >> tests;
    while(tests--){
        int start, endd;
        cin >> start >> endd;
        cout << values[endd] - values[start-1] << endl;
    }
    return 0;
}

