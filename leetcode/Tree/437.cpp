#include <unordered_map>
//
// Created by Mykyta on 8/24/2025.
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
    int calculateSum(TreeNode* node, int targetSum, long currentSum, std::unordered_map<long, int>& prefixCount) {
        if (node == nullptr) {
            return 0;
        }
        int total = 0;
        currentSum += node->val;
        total += prefixCount[currentSum - targetSum];
        prefixCount[currentSum]++;
        total += calculateSum(node->left, targetSum, currentSum, prefixCount);
        total += calculateSum(node->right, targetSum, currentSum, prefixCount);
        prefixCount[currentSum]--;
        return total;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long, int> prefixCount;
        prefixCount[0] = 1;
        return calculateSum(root, targetSum, 0, prefixCount);
    }
};