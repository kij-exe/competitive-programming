#include <bits/stdc++.h>
using namespace std;
//
// Created by Mykyta on 8/25/2025.
//
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen = 0;
        stack<int> bracketStack;
        bracketStack.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                bracketStack.push(i);
            }
            else if (s[i] == ')') {
                bracketStack.pop();
                if (bracketStack.empty()) {
                    bracketStack.push(i);
                }
                else {
                    maxLen = max(maxLen, i - bracketStack.top());
                }
            }
        }
        return maxLen;
    }
};