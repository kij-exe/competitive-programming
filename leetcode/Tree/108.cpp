#include <vector>
//
// Created by Mykyta on 8/23/2025.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* createTreeFromRange(int left, int right, vector<int>& nums) {
        if (left >= right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createTreeFromRange(left, mid, nums);
        node->right = createTreeFromRange(mid + 1, right, nums);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTreeFromRange(0, nums.size(), nums);
    }
};