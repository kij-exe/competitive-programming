//
// Created by Mykyta on 9/3/2025.
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
    // assume that after the head there are two sorted segments of given size
    // head is the node right before the first segment
    void mergeSegments(ListNode* head, int size) {
        ListNode* left = head, *right = head;
        for (int i = 0; i < size && right->next != nullptr; i++) {
            right = right->next;
        }
        if (right->next == nullptr) {
            return;
        }
        int leftCount = 0, rightCount = 0;
        while (leftCount < size && rightCount < size && left != right && right->next != nullptr) {
            if (left->next->val <= right->next->val) {
                leftCount++;
                left = left->next;
            }
            else {
                rightCount++;
                ListNode *nextRight = right->next->next;
                right->next->next = left->next;
                left->next = right->next;
                right->next = nextRight;
                left = left->next;
            }
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode *dummyHead = new ListNode(0, head);
        int size = 0;
        while (head != nullptr) {
            head = head->next;
            size++;
        }
        for (int i = 1; i < size; i *= 2) {
            ListNode* currentHead = dummyHead;
            while (currentHead->next != nullptr) {
                mergeSegments(currentHead, i);
                for (int j = 0; j < 2 * i && currentHead->next != nullptr; j++) {
                    currentHead = currentHead->next;
                }
            }
        }
        return dummyHead->next;
    }
};