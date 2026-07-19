/**
Approach: Maintain two stacks- push the root onto stack-1, pop the topmost from stack 1 and push onto stack 2. If the topmost has left and right children, push 
them onto stack 1 and continue. Lastly, pop from stack 2 into the answer array.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (root==nullptr){return ans;}
        stack <TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node= st1.top();
            st1.pop();
            st2.push(node);
            if (node->left!=nullptr){
                st1.push(node->left);
            }
            if (node->right!=nullptr){
                st1.push(node->right);
            }
        }
        while (!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
        
    }
};
