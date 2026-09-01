/*
Problem: Count Complete Tree Nodes 
Platform: LeetCode #222
Difficulty: Medium 

Approach:
1. For a complete Binary Tree, all the levels except possibly the last level, are completely filled and in the last level, all the nodes are to the left.
2. At each level, check if the left and right height are equal, if yes, use the formula for height, else check for the left and the right subtree recursively.

Time Complexity: O((log n)^2)
Space Complexity: O(1)

Date Solved: 2026-07-30
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
    int findHeightLeft(TreeNode* root){
        int height=0;
        TreeNode* node=root;
        while (node){
            height++;
            node=node->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* root){
        int height=0;
        TreeNode* node= root;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        int lh= findHeightLeft(root);
        int rh= findHeightRight(root);
        if (lh==rh){
            return (pow(2, lh))-1;
        }
        return countNodes(root->right)+ 1+ countNodes(root->left);
        
    }
};
