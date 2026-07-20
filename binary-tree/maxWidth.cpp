/*
Problem: Maximum Width of Binary Tree 
Platform: LeetCode #662
Difficulty: Medium 

Approach:
1.Follow the algorithm for level order traversal by maintaining a queue.
2. Keep a track of the first and last index of a level.
3. The indexing should be readjusted for the child nodes to prevent overflows.

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        queue <pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans=0;
        while(!q.empty()){
            long long  mmin= q.front().second;
            int size= q.size();
            long long  first, last;
            for (int i=0; i<size; i++){
                long long curidx= q.front().second-mmin;
                TreeNode* node= q.front().first;
                q.pop();
                if (i==0){
                    first= curidx;
                }
                if (i==size-1){
                    last=curidx;
                }
                if (node->left){
                    q.push({node->left, curidx*2+1});
                }
                if (node->right){
                    q.push({node->right, curidx*2+2});
                }
            }
            ans= max(ans, last-first+1);
        }
        return ans;

        
    }
};
