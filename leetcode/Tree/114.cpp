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
    TreeNode* createList(TreeNode* root, TreeNode* tail) {
        if (root == NULL) {
            return tail;
        }
        TreeNode* rightList = createList(root->right, tail);
        TreeNode* leftList = createList(root->left, rightList);
        root->left = NULL;
        root->right = leftList;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        createList(root, NULL);
    }
};