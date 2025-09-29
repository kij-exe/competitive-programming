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
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    // a stack of largest elements from a encountered
    // so far in increasing order
    vector<int> stack;
    // for a given subarray, element b[i] either can be preserved in z or not
    // if it can be preserved in a subarray starting from some j
    // then it can also be preserved in any subarray ending in any
    // position i <= k < n
    // so for a given element b[i] we need to find in how
    // many subarrays it can participate
    // the condition for it is:
    // subarray must contain an element >= b[i] in some
    // position l < i, while a[l] >= a[i]
    // in this way, a prefix maximum of subarray will be defined by
    // that element a[l]
    // then subarray [l, i] is a minimal subarray that is required
    // for element b[i] to be possible to preserve in z
    // so the total number of such subarrays is
    // (n - i) * (l + 1)
    ll result = 0;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && a[stack.back()] < a[i]) {
            stack.pop_back();
        }
        if (a[i] != b[i]) {
            // find the smallest element in stack such that b[i] <= a[l]
            int left = 0, right = stack.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int l = stack[mid];
                if (a[l] >= b[i]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (right != -1) {
                int l = stack[right];
                result += (ll)(n - i) * (l + 1);
            }
        }
        else {
            result += (ll)(n - i) * (i + 1);
        }
        stack.push_back(i);
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
