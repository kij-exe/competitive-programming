//
// Created by Mykyta on 10/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x: a) out << x;
    return out;
};

void solve() {
    int n, k;
    cin >> n >> k;
    int top = 0, topM = 0;
    int bot = n - 1, botM = n - 1;
    vector<char> outcome(n, '-');
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        if (c == '0') {
            top++;
            topM++;
        } else if (c == '1') {
            bot--;
            botM--;
        } else {
            topM++;
            botM--;
        }
    }
    if (k >= n) {
        cout << outcome << "\n";
        return;
    }
    for (int i = top; i < topM; i++) {
        outcome[i] = '?';
    }
    for (int i = botM + 1; i <= bot; i++) {
        outcome[i] = '?';
    }
    for (int i = topM; i <= botM; i++) {
        outcome[i] = '+';
    }
    cout << outcome << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
