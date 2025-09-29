//
// Created by Mykyta on 9/4/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define alphabetSize ('z' - 'a' + 1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (m > n) return ans;
        vector<int> currentCount(alphabetSize, 0);
        int numChars = 0; // number of letters used
        for (int i = 0; i < m; i++) {
            if (currentCount[p[i] - 'a'] == 0) {
                numChars++;
            }
            currentCount[p[i] - 'a']++;
        }
        // the matched state would correspond to all records in the currentCount
        // being 0, so every time a number in the dictionary changes from 0,
        // we know that there is either too many letters or not enough
        // so we add 1 to numChars indicating that there is a not-accounted for
        // character
        // when a number changes to 0, we subtract 1 to indicate that 1 letter is accounted for
        // so that when all letters are accounted for, numChar is 0
        for (int i = 0; i < m; i++) {
            int *letterCount = &currentCount[s[i] - 'a'];
            if (*letterCount == 0) {
                numChars++;
            }
            (*letterCount)--;
            if (*letterCount == 0) {
                numChars--;
            }
        }
        if (numChars == 0) {
            ans.push_back(0);
        }
        for (int i = 0; i < n - m; i++) {
            int *removedLetter = &currentCount[s[i] - 'a'];
            int *newLetter = &currentCount[s[i + m] - 'a'];
            if (*removedLetter == 0) {
                numChars++;
            }
            (*removedLetter)++;
            if (*removedLetter == 0) {
                numChars--;
            }
            if (*newLetter == 0) {
                numChars++;
            }
            (*newLetter)--;
            if (*newLetter == 0) {
                numChars--;
            }
            if (numChars == 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};