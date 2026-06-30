
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a, ranges::greater{});
    vector<bool> even(n);
    int i = 0, count = 1;
    for (int j = 1; j < n; j++) {
        if (a[j] == a[j - 1]) count++;
        else {
            a[i] = a[j - 1];
            even[i] = count % 2 == 0;
            i++;
        }
    }
    a[i] = a[n - 1];
    even[i] = count % 2 == 0;
    i++;
    int g = i;
    vector<bool> dp(g); // dp[i] = true if moving on i you can force a win
    int l = 0, r = 0;
    int wins = 0;
    // wins - number of moves between a[r]-k and a[r] starting on which you win
    while (r < g) {
        // shift the window to maintain 0 <= a[r] - a[l] <= k
        while (a[l] - a[r] > k) {
            if (dp[l]) wins--;
            l++;
        }
        if (l == r) {
            // no moves other than a[r]
            dp[r] = !even[r]; // win if the number of a[r]s is odd
        }
        else {
            // otherwise the opponent must have no winning moves
            // and number of a[r]s must be odd, so the opponent cannot pick
            // the same number, cornering us into picking a losing move after
            dp[r] = wins == 0 && !even[r];
        }
        if (dp[r]) wins++;
        if (!dp[r]) {
            cout << "YES" << endl;
            return;
        }
        r++;
    }
    cout << "NO" << endl;
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
