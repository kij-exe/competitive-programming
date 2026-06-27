//
// Created by Mykyta on 10/19/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 0, j = 0;
    int count1 = 0;
    int toProtect = 0;
    while (j < n) {
        if (j - i > k - 1) {
            if (s[i++] == '1') {
                count1--;
            }
        }
        if (s[j] == '1') {
            if (count1 == 0) {
                toProtect++;
            }
            count1++;
        }
        j++;
    }
    cout << toProtect << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
