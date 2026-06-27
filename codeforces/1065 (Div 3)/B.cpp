//
// Created by Mykyta on 12/13/2025.
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
    for(int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == -1 && a[n - 1] == -1) {
        a[0] = 0;
        a[n - 1] = 0;
    }
    else if (a[0] == -1) {
        a[0] = a[n - 1];
    }
    else if (a[n - 1] == -1) {
        a[n - 1] = a[0];
    }
    cout << abs(a[n - 1] - a[0]) << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
    }
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
