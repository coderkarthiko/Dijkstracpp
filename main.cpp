#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct graph {
    int n, m;
    vector<vector<pii>> g;
    vector<int> d;
};

void get(graph& x) {
    cin >> x.n >> x.m;
    x.g.resize(x.n);
    for(int i = 0; i < x.m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        x.g[u].push_back({w, v});
        x.g[v].push_back({w, u});
    }
}

void dijkstra(graph& x, int src) {   
    vector<bool> v(x.n, false); 
    x.d.assign(x.n, INT_MAX);     
    x.d[src] = 0;  
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        src = pq.top().second;
        for(auto p: x.g[src]) {
            x.d[p.second] = min(x.d[p.second], x.d[src] + p.first);
            if(!v[p.second]) {
                pq.push(p);
                v[p.second] = true;
            }
        }
        pq.pop();
    }
}

int main() {
    graph x;
    get(x);
    for(int i = 0; i < x.n; i ++) {
        dijkstra(x, i);
        for(auto d: x.d) {
            cout << d << " ";
        }
        cout << endl;
    }
}