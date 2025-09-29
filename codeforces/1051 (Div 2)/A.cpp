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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; i++) {
        if (a[l] == i) {
            l++;
        }
        else if (a[r] == i) {
            r--;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
