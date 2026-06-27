//
// Created by Mykyta on 10/19/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const int N = 200002;
bool notPrime[N];
vector<int> factors[N];

void calcFactors() {
    for (int i = 2; i < N; i++) {
        if (!notPrime[i]) {
            factors[i].push_back(i);
            for (int j = i + i; j < N; j += i) {
                notPrime[j] = true;
                factors[j].push_back(i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j : factors[a[i]]) {
            if (s.contains(j)) {
                cout << 0 << endl;
                return;
            }
            s.insert(j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j : factors[a[i] + 1]) {
            if (s.contains(j)) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    calcFactors();

    int t;
    cin >> t;
    while (t--)
        solve();
}
