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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> charge(m + 1, 0);
    vector<int> tripStart(m + 1, -1);
    for (int i = 0; i < k; i++) {
        int p, c;
        cin >> p >> c;
        if (tripStart[c] == -1) {
            tripStart[c] = p;
        }
        else if (tripStart[c] == p) {
            tripStart[c] = -1;
            charge[c] += 100;
        }
        else {
            charge[c] += abs(p - tripStart[c]);
            tripStart[c] = -1;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (tripStart[i] != -1) {
            charge[i] += 100;
        }
        cout << charge[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
