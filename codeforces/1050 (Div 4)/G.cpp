//
// Created by Mykyta on 9/20/2025.
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
    int maxNum = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxNum = max(maxNum, a[i]);
    }
    vector<int> divisorCount(maxNum + 1);
    int maxDiv = 0;
    // a set of all divisors that divided entire array
    // on the previous prefix
    // it is required to check since it can become
    // a new maxDiv
    vector<int> prevFullDivisors;
    for (int i = 0; i < n; i++) {
        vector<int> nextFullDivisors;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                // we want to maintain the divisor that divides
                // as many elements as possible
                // but not entire prefix
                divisorCount[j]++;
                if (divisorCount[j] != i + 1) {
                    maxDiv = max(maxDiv, divisorCount[j]);
                }
                else {
                    nextFullDivisors.push_back(j);
                }
                if (j * j == a[i]) continue;
                divisorCount[a[i] / j]++;
                if (divisorCount[a[i] / j] != i + 1) {
                    maxDiv = max(maxDiv, divisorCount[a[i] / j]);
                }
                else {
                    nextFullDivisors.push_back(a[i] / j);
                }
            }
        }
        for (int div: prevFullDivisors) {
            if (div == 1) continue;
            if (divisorCount[div] != i + 1) {
                maxDiv = divisorCount[div];
            }
        }
        prevFullDivisors = nextFullDivisors;
        cout << maxDiv << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
