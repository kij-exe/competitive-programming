//
// Created by Mykyta on 8/28/2025.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* previous = dummy;
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            previous->next = current->next;
            current->next = current->next->next;
            previous->next->next = current;
            previous = current;
            current = current->next;
        }
        return dummy->next;
    }
};