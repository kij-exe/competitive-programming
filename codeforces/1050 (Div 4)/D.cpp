#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> odds;
    ll evenSum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            evenSum += a;
        }
        else {
            odds.push_back(a);
        }
    }
    ll total = 0;
    if (odds.empty()) {
        cout << 0 << endl;
        return;
    }
    sort(odds.begin(), odds.end(), greater<>());
    total += evenSum;
    for (int i = 0; i < (odds.size() + 1) / 2; i++) {
        total += odds[i];
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
