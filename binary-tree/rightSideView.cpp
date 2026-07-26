/*
Problem: Right Side View 
Platform: LeetCode #199
Difficulty: Medium

Approach:
1. Use a recursive function to visit every level and maintain a track of whether the node is the first node in the level.
2. If yes, push it in the vector.

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
    void recursion(TreeNode* root, int level, vector <int> &res){
        if (root==nullptr){
            return;
        }
        if (level==res.size()){
            res.push_back(root->val);
        }
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector <int> res; int level=0;
        recursion(root, level, res);
        return res;        
    }
};
