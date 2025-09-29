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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        return left->val == right->val && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root, root);
    }
};