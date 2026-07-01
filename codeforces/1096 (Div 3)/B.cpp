
#include <bits/stdc++.h>
using namespace std;

#define NMAX 500001
#define MOD 1000000007
using ll = long long;

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void mulSelf(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll mul(ll a, ll b) {
    mulSelf(a, b);
    return a;
}

void addSelf(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll add(ll a, ll b) {
    addSelf(a, b);
    return a;
}

void solve() {
    int n;
    cin >> n;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '(') left++;
        else right++;
    }
    if (left == right) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}
