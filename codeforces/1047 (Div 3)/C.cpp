//
// Created by Mykyta on 9/26/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    ll a, b;
    cin >> a >> b;
    int power2 = 0;
    while (b % 2 == 0) {
        power2++;
        b /= 2;
    }
    if ((a % 2 == 0 && power2 == 0) || (a % 2 == 1 && power2 == 1)) {
        cout << -1 << endl;
        return;
    }
    if (power2 == 0) {
        cout << a * b + 1 << endl;
        return;
    }
    cout << a * b * (1 << (power2 - 1)) + 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
