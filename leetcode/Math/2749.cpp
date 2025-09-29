//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // min number of moves
    int countBits(long num) {
        int count = 0;
        while (num) {
            count += num % 2;
            num /= 2;
        }
        return count;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        long difference = num1;
        for (int i = 1; i <= 40; i++) {
            difference -= num2;
            if (difference < 0) {
                return -1;
            }
            if (i >= countBits(difference) && i <= difference) {
                return i;
            }
        }
        return -1;
    }
};