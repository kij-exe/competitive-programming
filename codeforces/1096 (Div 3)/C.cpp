
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

void swap(int &a, int &b) {
    const int t = a;
    a = b;
    b = t;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, c = 0, r = n - 1;
    while (c <= n - 1) {
        if (a[c] % 6 == 0) {
            swap(a[c], a[l++]);
        }
        c++;
    }
    c = l;
    while (c <= r) {
        if (a[c] % 2 == 0) {
            swap(a[c++], a[l++]);
        }
        else if (a[c] % 3 == 0) {
            swap(a[c], a[r--]);
        }
        else {
            c++;
        }
    }
    cout << a << endl;
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
