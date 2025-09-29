//
// Created by Mykyta on 9/2/2025.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* currentHead = dummyHead;
        while (currentHead != nullptr) {
            // find the last node in the block
            ListNode* blockTail = currentHead;
            for (int i = 0; i < k && blockTail != nullptr; i++) {
                blockTail = blockTail->next;
            }
            if (blockTail == nullptr) {
                break;
            }
            ListNode* nextHead = blockTail;
            blockTail = blockTail->next;
            // reverse the block
            ListNode* blockHead = currentHead->next;
            ListNode* prev = blockTail;
            while (blockHead != blockTail) {
                ListNode* temp = blockHead->next;
                blockHead->next = prev;
                prev = blockHead;
                blockHead = temp;
            }
            ListNode* temp = currentHead->next;
            currentHead->next = nextHead;
            currentHead = temp;
        }
        return dummyHead->next;
    }
};