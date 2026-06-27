//
// Created by Mykyta on 10/19/2025.
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
    if (n == 0) {
        cout << "YES" << endl;
        return;
    }
    while ((n & 1) == 0) {
        n >>= 1;
    }
    int digits = 32 - __builtin_clz(n);
    if (digits % 2 == 1 && ((n >> (digits / 2)) & 1) == 1) {
        cout << "NO" << endl;
        return;
    }
    int nO = n;
    int nC = 0;
    while (nO > 0) {
        nC = (nC << 1) | (nO & 1);
        nO >>= 1;
    }
    if (n == nC)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
