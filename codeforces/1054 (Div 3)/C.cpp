#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
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
    int n, k;
    cin >> n >> k;
    vector<bool> found(k, false);
    int foundCnt = 0;
    int kValues = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < k && !found[x]) {
            found[x] = true;
            foundCnt++;
        }
        else if (x == k) {
            kValues++;
        }
    }
    cout << max(kValues, k - foundCnt) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}
