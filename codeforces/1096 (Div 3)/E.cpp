
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    int row = 1;
    int max_row = 1;
    int height = a[n - 1];
    ll imm = height;
    for (int i = n - 2; i >= 0; i--) {
        int new_height = min(a[i], height);
        if (height == new_height) {
            row++;
            max_row = max(max_row, row);
        }
        else {
            row = 1;
        }
        height = new_height;
        imm += height;
    }
    cout << sum - imm + max_row - 1 << '\n';
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
