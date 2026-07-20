/*
Problem: Maximum Path Sum 
Platform: LeetCode #124
Difficulty: Hard 

Approach:
1. In the function to compute the height of a binary tree, modify it to return the sum of values of the node and the max of the path of left and right subtree.
2. Use a variable to update the maximum value of the sum of the node, left and right subtree.
3. Make sure to eliminate the negative values of the path sum since they reduce the maximum.

Time Complexity: O(n)
Space Complexity: O(n)

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
    int maxPath(TreeNode* root, int &maxi){
        if (root==nullptr){
            return 0;
        }
        int left= max(0, maxPath(root->left, maxi));
        int right= max(0, maxPath(root->right, maxi));
        maxi= max(maxi, root->val+ left+right);
        return root->val+ max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPath(root, maxi);  
        return maxi;      
    }
};
