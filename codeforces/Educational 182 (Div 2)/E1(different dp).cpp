//
// Created by Mykyta on 9/23/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 998244353
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

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

vector<ll> constructDp(const vector<int>& a) {
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
    vector<ll> dp(a.size());
    // at each step j c[i] is the number of subsequences
    // from a[0..j] that have a left view of leftView[0..j]
    vector<ll> c(k + 1, 0);
    c[0] = 1;
    for (int i = 0; i < a.size(); i++) {
        // process elements of a one by one
        for (int j = 1; j <= k; j++) {
            // if a[i] is smaller than the next element of the left view
            // then we can form a subsequence by taking a
            // valid subsequence of the same leftView and
            // either include / not include this element
            if (a[i] <= leftView[j - 1]) {
                c[j] = (c[j] * 2) % MOD;
            }
            // if a[i] is the same then we can ALSO form
            // a valid subsequence by including it and
            // taking any valid subsequence of a leftView
            // without the last element
            if (a[i] == leftView[j - 1]) {
                addSelf(c[j], c[j - 1]);
            }
        }
        dp[i] = c[k];
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
