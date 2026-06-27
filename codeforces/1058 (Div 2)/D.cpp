//
// Created by Mykyta on 10/17/2025.
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
    vector<int> known_indices, unknown_indices;
    vector<int> result(2 * n);
    unknown_indices.push_back(0);
    for (int i = 1; i < 2 * n; i++) {
        int k = unknown_indices.size() + 1;
        cout << "? " << k << ' ';
        for (int j: unknown_indices) {
            cout << j + 1 << ' ';
        }
        cout << i + 1 << endl;
        cout.flush();
        int val;
        cin >> val;
        if (val == 0) {
            unknown_indices.push_back(i);
        }
        else {
            result[i] = val;
            known_indices.push_back(i);
        }
    }
    for (int i: unknown_indices) {
        cout << "? " << n + 1 << ' ';
        for (int j: known_indices) {
            cout << j + 1 << ' ';
        }
        cout << i + 1 << endl;
        cout.flush();
        cin >> result[i];
    }
    cout << "! ";
    for (int i = 0; i < 2 * n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
