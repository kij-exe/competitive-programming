//
// Created by Mykyta on 10/8/2025.
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
    string res;
    cin >> res;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string turns;
    cin >> turns;
    string prefix;
    for (int i = 0; i < k; i++) {
        if (turns[i] == 'D') {
            res += s[i];
        }
        else {
            prefix += s[i];
        }
    }
    ranges::reverse(prefix);
    cout << prefix + res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
