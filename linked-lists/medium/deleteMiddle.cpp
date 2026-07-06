/*
Problem: Delete the Middle Node 
Platform: LeetCode #2095
Difficulty: Medium 

Approach:
1. Use the slow and fast pointers to traverse to the middle node.
2. Adjust the links to delete the middle node.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-06
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head==nullptr || head->next== nullptr){
            return nullptr;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        ListNode* prev= nullptr;

        while (fast!=nullptr && fast->next!=nullptr){
            prev= slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        prev->next= slow->next;
        
        return head;        
    }
};
