//
// Created by Mykyta on 9/4/2025.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode *pointer = head;
        while (pointer) {
            size++;
            pointer = pointer->next;
        }
        ListNode *prev = nullptr, *current = head;
        for (int i = 0; i < size/2; i++) {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        if (size % 2 != 0) {
            current = current->next;
        }
        while (current) {
            if (current->val != prev->val) {
                return false;
            }
            current = current->next;
            prev = prev->next;
        }
        return true;
    }
};