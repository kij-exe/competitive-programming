//
// Created by Mykyta on 9/24/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x: a) out << x << ' ';
    return out;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    // count of each number in b
    vector<int> occ(n + 1, 0);
    vector<vector<int> > occSet(n + 1);
    // for array a to exist
    // each number in b must be a factor of how many times it occurs
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        occ[ai]++;
        occSet[ai].push_back(i);
    }
    int nextNum = 1;
    for (int i = 1; i <= n; i++) {
        if (occ[i] % i != 0) {
            cout << -1 << endl;
            return;
        }
        for (int j = 0; j < occ[i]; j++) {
            a[occSet[i][j]] = nextNum;
            if ((j + 1) % i == 0) nextNum++;
        }
    }
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
