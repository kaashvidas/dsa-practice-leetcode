/*
Problem: Check for Balanced Tree
Platform: LeetCode #110
Difficulty: Easy

Approach:
1. Compute the height for the right and the left subtrees.
2. If the diff between the heights is more than 1, return false.
3. Check for the right and left subtrees too.

Time Complexity: O(n^2)
Space Complexity: O(h)

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
    int height(TreeNode* root){
        if (root==nullptr){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr){
            return true;
        }
        int lh= height(root->left);
        int rh= height(root->right);
        if (abs(lh-rh)>1){return false;}
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        if (!left||!right){
            return false;
        }
        return true;  
    }
};
