/*
Problem: ZigZag Level Order Traversal
Platform: LeetCode #103 
Difficulty: Meedium 

Approach:
1. Use the approach for the level order traversal using a queue.
2. While filling the array, fill alternately- first in the forward direction and then in the back direction.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if (root==nullptr){
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        int cnt=0;
        while (!q.empty()){
           
            int size= q.size();
            vector <int> level(size);
            for (int i=0; i<size; i++){
                TreeNode* node= q.front();
                q.pop();
                int idx= (cnt%2==0)? i: size-i-1;
                level[idx]= node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
            cnt++;
        }
        return ans;
        
    }
};
