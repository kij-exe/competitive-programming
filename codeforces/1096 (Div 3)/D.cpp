
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

int getPalMex(vector<int>& a, int l, int r, int n) {
    unordered_set<int> s;
    while (l >= 0 && r < n) {
        if (a[l] != a[r]) break;
        s.insert(a[l]);
        l--;
        r++;
    }
    for (int i = 0; i <= n; i++) {
        if (!s.contains(i)) return i;
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    n = 2*n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int zeros[2];
    int z_i = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zeros[z_i++] = i;
        }
    }
    int mex1 = getPalMex(a, zeros[0], zeros[0], n);
    int mex2 = getPalMex(a, zeros[1], zeros[1], n);
    int sumz = zeros[0] + zeros[1];
    int m1 = sumz / 2;
    int m2 = m1 + (sumz % 2 == 0 ? 0 : 1);
    int mex3 = getPalMex(a, m1, m2, n);
    cout << max(max(mex1, mex2), mex3) << endl;
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
