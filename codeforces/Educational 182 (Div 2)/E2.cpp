//
// Created by Mykyta on 9/23/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 998244353
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

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

void mulSelf(ll &a, ll b) {
    a = (a * b) % MOD;
}

ll mul(ll a, ll b) {
    mulSelf(a, b);
    return a;
}

class SegmentTree {
    vector<int> originalArray;
    vector<ll> treeArray;
    int n;

    void build(int node, int start, int end) {
        if (start + 1 >= end) {
            treeArray[node] = originalArray[start];
            return;
        }
        treeArray[node] = 1;
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid, end);
    }

    void propagate(int node) {
        mulSelf(treeArray[node * 2], treeArray[node]);
        mulSelf(treeArray[node * 2 + 1], treeArray[node]);
        treeArray[node] = 1;
    }

    ll query(int node, int start, int end, int i) {
        if (start + 1 >= end) {
            return treeArray[node];
        }
        int mid = (start + end) / 2;
        if (i < mid) {
            return mul(treeArray[node], query(node * 2, start, mid, i));
        }
        return mul(treeArray[node], query(node * 2 + 1, mid, end, i));
    }

    void addNum(int node, int start, int end, int i, ll num) {
        if (start + 1 >= end) {
            addSelf(treeArray[node], num);
            return;
        }
        propagate(node);
        int mid = (start + end) / 2;
        if (i < mid) {
            addNum(node * 2, start, mid, i, num);
        }
        else {
            addNum(node * 2 + 1, mid, end, i, num);
        }
    }

    void doubleSegment(int node, int start, int end, int l, int r) {
        if (r <= start || end <= l) {
            // no overlap
            return;
        }
        if (l <= start && end <= r) {
            // total overlap
            mulSelf(treeArray[node], 2);
            return;
        }
        int mid = (start + end) / 2;
        doubleSegment(node * 2, start, mid, l, r);
        doubleSegment(node * 2 + 1, mid, end, l, r);
    }
public:
    SegmentTree(const vector<int> &v) {
        originalArray = v;
        n = originalArray.size();
        treeArray.resize(n * 4);
        build(1, 0, n);
    }

    ll query(int i) {
        return query(1, 0, n, i);
    }

    void addNum(int i, ll num) {
        addNum(1, 0, n, i, num);
    }

    // double a segment [l..r)
    void doubleSegment(int l, int r) {
        doubleSegment(1, 0, n, l, r);
    }
};

vector<ll> constructDp(const vector<int>& a) {
    vector<int> leftView;
    leftView.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > leftView.back()) {
            leftView.push_back(a[i]);
        }
    }
    leftView.pop_back();
    int k = leftView.size();
    // at step j, dp[i] is the number of subsequences
    // of a[0..i] with the leftView[0..j - 1]
    // initially j = 0, so there is only one
    // way to construct empty leftView
    vector<ll> dp(a.size());
    // at each step j c[i] is the number of subsequences
    // from a[0..j] that have a left view of leftView[0..j]
    vector<int> c(k + 1, 0);
    c[0] = 1;
    SegmentTree st(c);
    for (int i = 0; i < a.size(); i++) {
        // process elements of a one by one
        // let the first element in leftView
        // that is >= a[i] be at index j
        // then for all subsequences of length
        // >= j + 1, we can double the value
        // since with a[i] all previously
        // valid subsequences remain valid
        // regardless of whether a[i] is present or not
        int j = lower_bound(leftView.begin(), leftView.end(), a[i]) - leftView.begin();
        if (j < k) {
            st.doubleSegment(j + 1, k + 1);
            // if there is an element a[i] in leftView at position j
            // then the sequences of length j + 1 can be constructed
            // from the sequences of length j by adding element a[i] to them
            if (leftView[j] == a[i]) {
                st.addNum(j + 1, st.query(j));
            }
        }
        dp[i] = st.query(k);
    }
    return dp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxElem = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxElem = max(maxElem, a[i]);
    }
    vector<ll> Ldp = constructDp(a);
    vector<ll> Rdp = constructDp({a.rbegin(), a.rend()});
    reverse(Rdp.begin(), Rdp.end());
    ll result = 0;
    vector<ll> power2(n + 1);
    power2[0] = 1;
    for (int i = 1; i <= n; i++) {
        power2[i] = (power2[i - 1] * 2) % MOD;
    }
    ll runningSum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == maxElem) {
            addSelf(result, mul(add(runningSum, Ldp[i]), Rdp[i]));
        }
        mulSelf(runningSum, 2);
        if (a[i] == maxElem) {
            addSelf(runningSum, Ldp[i]);
        }
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
