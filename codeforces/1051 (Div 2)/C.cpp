//
// Created by Mykyta on 9/20/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n;
    cin >> n;
    vector<int> indegree(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--; v--;
        // create an edge u->v indicating that in order
        // to maximize the arrangement, p(u) > p(v)
        // and vice verse
        if (x > y) {
            indegree[v]++;
            adj[u].push_back(v);
        }
        else {
            indegree[u]++;
            adj[v].push_back(u);
        }
    }
    // nodes with indegree of 0
    // they can be assigned the largest currently available number
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int i = n;
    vector<int> arrangementOrder(n);
    while (!q.empty()) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            int u = q.front();
            q.pop();
            arrangementOrder[u] = i--;
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    cout << arrangementOrder << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
