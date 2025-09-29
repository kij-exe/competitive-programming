#include <bits/stdc++.h>

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
    int getDecimalValue(ListNode *head) {
        int numNodes = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            numNodes++;
            temp = temp->next;
        }
        int result = 0;
        while (head != NULL) {
            result += head->val << (numNodes - 1);
            numNodes--;
            head = head->next;
        }
        return result;
    }
};
