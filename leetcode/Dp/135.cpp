#include <algorithm>
//
// Created by Mykyta on 7/18/2025.
//
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int total = 1;
        int rating = 1;
        int minimum = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                rating++;
            }
            else if (ratings[i] < ratings[i - 1]) {
                rating--;
            }
            total += rating;
            minimum = min(minimum, rating);
        }
        return total + (1 - minimum) * n;
    }
};
