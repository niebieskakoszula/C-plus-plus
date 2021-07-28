//https://www.spoj.com/problems/LCA/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> edges;
vector<pair<int, int>> path;
vector<int> first;
vector<vector<pair<int,int>>> mins;

int FindRootIndex(vector<bool> indexes, int n){
    for(int i = 1; i <= n; ++i)
        if(!indexes[i]) 
			return i;
}

void DFS(int u, int h){
    first[u] = path.size();
    path.push_back({h,u});
    
    for(int v = 0; v < edges[u].size(); v++){
        DFS(edges[u][v], h + 1);
        path.push_back({h,u});
    }
}


void GenerateMins(){
    int M = path.size();
    int logM = (int) log2(M);
    mins.assign(M, vector<pair<int,int> >(logM + 1));
    
    for(int i = 0; i < M; i++){
        mins[i][0] = path[i];
    }

    for(int i = 1; i <= logM; i++){
        for(int j = 0; j + (1 << i) <= M; j++)
            mins[j][i] = min(mins[j][i - 1], mins[j + (1 << (i - 1))][i - 1]);
    }
}

int Query(int u, int v){
    int left = first[u];
    int right = first[v];
    if(left > right) swap(left, right);
    int lenght = right - left + 1;
    int kebab = (int)log2(lenght);
    
    return min(mins[left][kebab], mins[right - (1 << kebab) + 1][kebab]).second;
}

int main()
{
    int tests;
    cin >> tests;
    for(int test = 0; test < tests; ++test){
        int n, m, input;
        cin >> n;
        
        edges.assign(n + 1, vector<int>());
        path.clear();
        first.assign(n + 1, -1);

        vector<bool> isNotRoot(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> m;
            for(int j = 0; j < m; ++j){
                cin >> input;
                edges[i].push_back(input);
                isNotRoot[input] = true;
            }
        }

		

        DFS(FindRootIndex(isNotRoot, n), 0);
        GenerateMins();
        
        int q, left, right;
        cin >> q;
        int results[q];
        for(int i = 0; i < q; ++i){
            cin >> left >> right;
            results[i] = Query(left, right);
        }
        
        cout << "Case " << test + 1 << ":" << endl;
        for(int i = 0; i < q; ++i)
            cout << results[i] << endl;

    }
    return 0;
}
