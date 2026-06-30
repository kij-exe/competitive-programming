
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n+1, vector(n+1, false));
    for (int left = 0; left < n; left++) {
        unordered_set<int> s;
        int minimum = n + 1, maximum = -1;
        for (int right = left; right < n; right++) {
            if (s.contains(a[right])) break;
            s.insert(a[right]);
            minimum = min(minimum, a[right]);
            maximum = max(maximum, a[right]);
            if (right - left == maximum - minimum) {
                dp[minimum][maximum] = true;
            }
        }
    }
    int max_length = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j+1 + j-i <= n; j++) {
            if (dp[i][j] && dp[j+1][j+1 + j-i]) {
                max_length = max(max_length, j - i + 1);
            }
        }
    }
    cout << max_length << endl;
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
