//
// Created by Mykyta on 9/21/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefSum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefSum[i + 1] = prefSum[i] + a[i];
    }
    for (int l = 1; l < n - 1; l++) {
        for (int r = l + 1; r < n; r++) {
            int s1 = (prefSum[l]) % 3;
            int s2 = (prefSum[r] - prefSum[l]) % 3;
            int s3 = (prefSum[n] - prefSum[r]) % 3;
            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s3 != s1)) {
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << "0 0" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
