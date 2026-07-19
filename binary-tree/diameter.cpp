/*
Problem: Diameter of Binary Tree 
Platform: LeetCode #543 
Difficulty: Easy

Approach:
1. Use the height function to calculate the left and right subtree height.
2. At the same time, update the variable maxi to lh+rh.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-20
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
  
    int height(TreeNode* root, int &maxi){
        if (root==nullptr){
            return 0;
        }
        int lh= height(root->left, maxi);
        int rh= height(root->right, maxi);
        maxi= max(maxi, lh+ rh);
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        height(root, maxi);
        return maxi;        
    }
};
