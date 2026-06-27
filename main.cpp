
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {

=======
void mulSelf(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll mul(ll a, ll b) {
    mulSelf(a, b);
    return a;
}

void addSelf(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll add(ll a, ll b) {
    addSelf(a, b);
    return a;
}

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int &el: a) cin >> el;
    // a set of elements a[l:r] kept at size = k
    unordered_map<int> KMap;
    int KMapSize = 0;
    // a set of elements a[m:r] kept at size < k
    // (exactly one element after size=k block)
    unordered_map<int> KLessMap;
    int KLessMapSize = 0;
    int lP = 0, mP = 0, rP = 0;
    ll count = 0;
    while (rP < n) {

        KMap.insert(a[rP]);
        KLessMap.insert(a[rP]);
        while (mP <= rP && KLessMap.size() >= k) {
            KLessMap.erase(KLessMap.find(a[mP++]));
        }
        while (lP <= rP && KMap.size() > k) {
            KMap.erase(KMap.find(a[lP++]));
        }
        if (KMap.size() == k) {
            cout << lP << " " << mP << " " << rP << endl;
            count += max(min(rP - lP + 1, r) - max(rP - mP + 2, l) + 1, 0);
        }
        rP++;
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}
