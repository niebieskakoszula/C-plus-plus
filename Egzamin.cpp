//https://pl.spoj.com/problems/AL_06_08/

#include <bits/stdc++.h>
using namespace std;
 
const int max_s = 100000;
int n;
 
int times[max_s], memo[max_s];
 
/*
1 2 3 4 5 6
6 + solve(5) // 1 2 3 4 5
5 6 + solve(4) // 1 2 3 4
4 5 6 + solve(3) // 1 2 3
*/
//group time + solve(reszty)
int solve(int s)
{
    if (s == -1){
        return 0;
    }
    if(memo[s]!=-1){
        return memo[s];
    }
    int group_time=0;
    memo[s] = INT_MAX; // numeric_limits<int>::max();
    for(int i = s; i >= max(s - n + 1, 0); i--) {
        group_time = max(group_time, times[i]);
        memo[s]=min(group_time + solve(i-1), memo[s]);
    }
    return memo[s];
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, start_h, start_m;
        scanf("%d %d %02d:%02d", &s, &n, &start_h, &start_m);
        for (int i = 0; i < s; ++i) {
            scanf("%d", times + i);
            memo[i] = -1;
        }
        int exam_time = solve(s-1);
        int end_time = (start_h * 60 + start_m + exam_time) % (24 * 60);
        printf("%02d:%02d\n", end_time / 60, end_time % 60);
    }
 
    return 0;
}
