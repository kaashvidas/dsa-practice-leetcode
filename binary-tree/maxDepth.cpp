/*
Problem: Maximum Depth of Binary Tree
Platform: LeetCode #104 
Difficulty: Easy

Approach:
1. Return the 1+ maximum of the left and the right subtree recursively.

Time Complexity: O(n)
Space Complexity: O(log2n)

Date Solved: 2026-07-19
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
    int maxDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        int lh= maxDepth(root->left);
        int rh= maxDepth(root->right);
        return 1+ max(lh, rh);
        
    }
};
