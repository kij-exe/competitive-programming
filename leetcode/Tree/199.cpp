#include <queue>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> level;
        vector<int> result;
        int size = 1;
        if (root != NULL) {
            level.push(root);
        }
        while (level.size() > 0) {
            result.push_back(level.front()->val);
            for (int i = 0; i < size; i++) {
                TreeNode* nextNode = level.front();
                level.pop();
                if (nextNode->right != NULL) {
                    level.push(nextNode->right);
                }
                if (nextNode->left != NULL) {
                    level.push(nextNode->left);
                }
            }
            size = level.size();
        }
        return result;
    }
};