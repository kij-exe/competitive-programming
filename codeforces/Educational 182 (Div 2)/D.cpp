//
// Created by Mykyta on 9/22/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n, y;
    cin >> n >> y;
    vector<int> a(n);
    int maxA = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    if (maxA == 1) {
        cout << n << endl;
        return;
    }
    // cnt[i] the number of elements i in a
    vector<int> cnt(maxA + 1, 0);
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    // allows to calculate the number of elements in the range in O(1)
    vector<int> prefSum(maxA + 1, 0);
    for (int i = 1; i <= maxA; i++) {
        prefSum[i] = prefSum[i - 1] + cnt[i];
    }
    ll maxProfit = LONG_LONG_MIN;
    for (int x = 2; x <= maxA; x++) {
        ll profit = 0;
        // iterate through all price tags that might
        // need to be printed
        // these are 1 to roundUp(maxA / x) since every a < maxA
        for (int p = 1; p <= (maxA + x - 1) / x; p++) {
            // numbers that when divided by x give p are in the range
            // [p * x, p * x + x - 1]
            int ub = p * x, lb = (p - 1) * x + 1; // [lb, ub] range
            if (lb >= maxA) break;
            ll totalCount = prefSum[min(maxA, ub)] - prefSum[lb - 1];
            profit += totalCount * p;
            profit -= y * max(0ll, totalCount - cnt[p]);
        }
        maxProfit = max(maxProfit, profit);
    }
    cout << maxProfit << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
