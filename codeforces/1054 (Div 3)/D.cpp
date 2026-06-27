
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

ll getMin(string &a, char c) {
    int n = a.size();
    // prefix[i] = minimum number of steps
    // to put all chars c at the end for a[0..i)
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    ll cCount = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i];
        if (a[i] == c) {
            cCount++;
        }
        else {
            prefix[i + 1] += cCount;
        }
    }
    // suffix[i] = minimum number of steps
    // to put all chars c at the start of a[i..)
    vector<ll> suffix(n + 1);
    suffix[n] = 0;
    cCount = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1];
        if (a[i] == c) {
            cCount++;
        }
        else {
            suffix[i] += cCount;
        }
    }
    ll minSteps = LONG_LONG_MAX;
    for (int i = 0; i <= n; i++) {
        minSteps = min(minSteps, prefix[i] + suffix[i]);
    }
    return minSteps;
}

void solve() {
    int n;
    cin >> n;
    string v;
    cin >> v;
    cout << min(getMin(v, 'a'), getMin(v, 'b')) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}
