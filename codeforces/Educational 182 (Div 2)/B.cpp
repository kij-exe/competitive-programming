//
// Created by Mykyta on 9/21/2025.
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
    vector<int> a(n);
    vector<bool> visited(n + 1, false);
    vector<int> zeroPos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        visited[a[i]] = true;
        if (a[i] == 0) zeroPos.push_back(i);
    }
    if (zeroPos.size() == 1) {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) a[zeroPos[0]] = i;
        }
    }
    int l = 0;
    while (l < n && a[l] == l + 1) l++;
    int r = n - 1;
    while (r >= l && a[r] == r + 1) r--;
    if (l >= r) {
        cout << 0 << endl;
        return;
    }
    cout << r - l + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
