//
// Created by Mykyta on 9/11/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long) (n / 2) * (m - m / 2) + (long long) (m / 2) * (n - n / 2);
    }
};