//
// Created by Mykyta on 10/15/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        if (edges[i].first < edges[i].second) {
            a++;
        }
        else {
            b++;
        }
    }
    cout << "YES" << endl;
    cout << ((a > b) ? a : b) << endl;
    for (int i = 0; i < m; i++) {
        if (a < b ^ edges[i].first < edges[i].second) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
