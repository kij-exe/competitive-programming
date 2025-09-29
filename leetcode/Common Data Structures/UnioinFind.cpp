//
// Created by Mykyta on 9/8/2025.
//

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> root;
    vector<int> size;
public:
    explicit UnionFind(int n) {
        root.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (root[x] == x)
            return x;
        const int parentRoot = find(root[x]);
        root[x] = parentRoot;
        return parentRoot;
    }

    void unite(int x, int y) {
        const int xRoot = find(x), yRoot = find(y);
        const int xSize = size[xRoot], ySize = size[yRoot];
        if (xSize < ySize) {
            root[xRoot] = yRoot;
            size[yRoot] += xSize;
        }
        else {
            root[yRoot] = xRoot;
            size[xRoot] += ySize;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
