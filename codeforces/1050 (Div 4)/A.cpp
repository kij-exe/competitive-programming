#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int x, n;
    cin >> x >> n;
    cout << (n % 2 == 0 ? 0 : x) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
