//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int x = 0, y = 0;
        int i = 1;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            if (digit < 2 && n > 0) {
                digit += 10;
                n -= 1;
            }
            x = x + (digit / 2) * i;
            y = y + ((digit + 1) / 2) * i;
            i *= 10;
        }
        return vector<int>{x, y};
    }
};