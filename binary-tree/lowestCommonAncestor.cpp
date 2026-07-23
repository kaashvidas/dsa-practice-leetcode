/*
Problem: Lowest Common Ancestor 
Platform: LeetCode #236
Difficulty: Hard 

Approach:
1. Start with the root and traverse through the tree recursively (dfs).
2. If left is null, return right, else return left. If both are not null, that means that particular node is the lowest common ancestor.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-23
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr|| root==p|| root==q){
            return root;
        }
        TreeNode* right= lowestCommonAncestor(root->left, p, q);
        TreeNode* left= lowestCommonAncestor(root->right, p, q);

        if (left==nullptr){
            return right;
        }
        else if (right==nullptr){
            return left;
        }
        else {
            return root;
        }
        
    }
};
