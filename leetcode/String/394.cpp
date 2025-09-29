//
// Created by Mykyta on 9/5/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        strStack.push({});
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                size_t offset;
                int count = stoi(s.substr(i), &offset);
                i += offset - 1;
                numStack.push(count);
            }
            else if (s[i] == '[') {
                strStack.push({});
            }
            else if (s[i] == ']') {
                const int n = numStack.top();
                numStack.pop();
                string formedString = strStack.top();
                strStack.pop();
                string &outerString = strStack.top();
                outerString.reserve(outerString.length() + n * formedString.length());
                for (int j = 0; j < n; j++) {
                    outerString += formedString;
                }
            }
            else {
                strStack.top() += s[i];
            }
            i++;
        }
        return strStack.top();
    }
};
