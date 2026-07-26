/*
Problem: Symmetric Binary Tree 
Platform: LeetCode #101
Difficulty: Easy

Approach:
1. Use a recursive function to check if the left and right nodes are equivalent.
2. Move to the left's left and right's right and perform the same comparison then.
3. Return false if not equivalent at any point.

Time Complexity: O(n)
Space Complexity: O(h)

Date Solved: 2026-07-26
*/



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
    bool isSymmetric(TreeNode* root) {
        return (root==nullptr || symmetricHelp(root->left, root->right));  
    }
    bool symmetricHelp(TreeNode* left, TreeNode* right){
        if (left==nullptr || right==nullptr){
            return left==right;
        }
        if (left->val!=right->val){
            return false;
        }
        return symmetricHelp(left->left, right->right) && symmetricHelp(left->right, right->left);
    }
};
