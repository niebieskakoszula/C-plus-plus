//https://pl.spoj.com/problems/DDZ3/

    #include <bits/stdc++.h>
    using namespace std;
     
    vector<vector<int>> edges;
     
    int eat(int current_vertex) {
        queue<int> to_visit;
        to_visit.push(current_vertex);
        vector<int> distance(edges.size(),0);
        distance[current_vertex] = 1;
     
        while(!to_visit.empty()) {
            int first_vertex = to_visit.front();
            to_visit.pop();
            for (int next_vertex: edges[first_vertex]) {
                if (distance[next_vertex] == 0) {
                    distance[next_vertex] = distance[first_vertex] + 1;
                    to_visit.push(next_vertex);
                }
            }
        }
        return *max_element(distance.begin(), distance.end());
    }
     
    int main() {
        int n, max_vertex = 0;
        cin>>n;
        edges.resize(n);
        for(int i = 0; i < n; ++i) {
            int m;
            cin>>m;
            edges[i].resize(m);
            for(int j = 0; j < m; ++j) {
                cin>>edges[i][j];
                --edges[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            max_vertex = max(max_vertex,eat(i));
        }
        cout << max_vertex << endl;
        return 0;
    }
     
