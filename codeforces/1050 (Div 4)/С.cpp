//
// Created by Mykyta on 9/18/2025.
//
#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int total = 0;
    int prevMin = 0, prevSide = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        total += a - prevMin;
        if (b == prevSide ^ (a - prevMin) % 2 == 0) {
            total--;
        }
        prevMin = a;
        prevSide = b;
    }
    total += m - prevMin;
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
