#include <bits/stdc++.h>

using namespace std;

long long Silnia(long long maxx){
    long long silnia = 1, licznik = 1;
    while(silnia <= maxx){
        silnia *= licznik;
        licznik++;
    }
    return licznik;
}

int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<Silnia(b) - Silnia(a-1)<<endl;
    return 0;
}
