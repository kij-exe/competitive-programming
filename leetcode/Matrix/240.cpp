//
// Created by Mykyta on 9/4/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            if (target < matrix[row][col]) {
                // if the target is smaller, then it can't possibly be at this row
                col--;
            }
            else if (target > matrix[row][col]) {
                // if the target is larger, it can't possibly be in this col
                row++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};