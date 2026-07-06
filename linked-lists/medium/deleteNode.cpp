/*
Problem: Delete Node in Linked List
Platform: LeetCode #237
Difficulty: Medium 

Approach:
1. Since the head of the linked list is not given and only the node to be deleted is given, iterate from the node till the end.
2. At each step, copy the data from the successive node onto the previous node. 
3. Change the pointer of the second last node to null and delete the last node.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-06
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev= nullptr;
        while (node->next!=nullptr){
            node->val= node->next->val;
            prev= node;
            node= node->next;
        }
        prev->next= nullptr;
        delete node;             
    }
};
