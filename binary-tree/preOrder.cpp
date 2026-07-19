/*
Problem: Binary Tree Preorder Traversal
Platform: LeetCode #144
Difficulty: Easy

Approach:
1. Use the recursive function to push back a node's value and then call for left and right nodes respectively.

Time Complexity: O(n)
Space Complexity: O(1)

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
       void preOrder(TreeNode* root, vector <int> &ans){
        if (root==nullptr){
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
       }
       vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;a
        preOrder(root, ans);
        return ans;        
    }
};
