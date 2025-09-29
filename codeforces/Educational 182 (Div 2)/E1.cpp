//
// Created by Mykyta on 9/23/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 998244353
using ll = long long;

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x: a) out << x << ' ';
    return out;
}

void addSelf(ll &a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll add(ll a, ll b) {
    addSelf(a, b);
    return a;
}

vector<ll> constructDp(const vector<int> &a) {
    vector<int> leftView;
    leftView.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > leftView.back()) {
            leftView.push_back(a[i]);
        }
    }
    leftView.pop_back();
    int k = leftView.size();
    // at step j, dp[i] is the number of subsequences
    // of a[0..i] with the leftView[0..j - 1]
    // initially j = 0, so there is only one
    // way to construct empty leftView
    vector<ll> dp(a.size(), 1);
    for (int j = 0; j < k; j++) {
        vector<ll> nextDp(a.size(), 0);
        nextDp[0] = j == 0 ? 1 : 0;
        for (int i = 1; i < a.size(); i++) {
            nextDp[i] = nextDp[i - 1];
            if (a[i] <= leftView[j]) {
                addSelf(nextDp[i], nextDp[i - 1]);
            }
            if (a[i] == leftView[j]) {
                addSelf(nextDp[i], dp[i - 1]);
            }
        }
        dp = nextDp;
    }
    return dp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxElem = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxElem = max(maxElem, a[i]);
    }
    vector<ll> Ldp = constructDp(a);
    vector<ll> Rdp = constructDp({a.rbegin(), a.rend()});
    reverse(Rdp.begin(), Rdp.end());
    ll result = 0;
    vector<ll> power2(n + 1);
    power2[0] = 1;
    for (int i = 1; i <= n; i++) {
        power2[i] = (power2[i - 1] * 2) % MOD;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != maxElem) continue;
        for (int j = i; j < n; j++) {
            if (a[j] != maxElem) continue;
            ll comb = 1;
            if (i > 0) {
                comb *= Ldp[i - 1];
            }
            if (j < n - 1) {
                comb = (comb * Rdp[j + 1]) % MOD;
            }
            comb = (power2[max(0, j - i - 1)] * comb) % MOD;
            addSelf(result, comb);
        }
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
