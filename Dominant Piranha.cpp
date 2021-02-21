//https://codeforces.com/contest/1433/problem/C

#include <bits/stdc++.h>

using namespace std;

vector <int> A;

int main()
{
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        A.resize(n);
        int maxx=0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            if(A[i] > maxx) {
                maxx = A[i];
            }
        }
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if(A[i] != maxx) {
                continue;
            }
            if(i-1 >= 0 && A[i-1] < maxx) {
                pos = i + 1;
                break;
            }
            if(i+1 < n && A[i+1] < maxx) {
                pos = i + 1;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}
