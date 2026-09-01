/*
Problem: Binary Tree Inorder Traversal
Platform: LeetCode #94
Difficulty: Easy

Approach:
1. Use the recursive function to first call the right child, push the current val in the answer array and then call for left child.

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
    void inOrder(TreeNode* root, vector <int>&ans){
        if (root==nullptr){
            return;
        }
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        inOrder(root, ans);
        return ans;        
    }
};
