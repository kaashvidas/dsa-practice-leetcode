/*
Problem: Binary Tree Postorder Traversal
Platform: LeetCode #145
Difficulty: Easy

Approach:
1. Use the recursive function to call for left child, right child and then push the value of the current node.

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
    void postOrder(TreeNode* root, vector <int>&ans){
        if (root==nullptr){
            return;
        }
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans;
        postOrder(root, ans);
        return ans;        
    }
};
