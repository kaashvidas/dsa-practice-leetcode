/*
Problem: Linked List Cycle II
Platform: LeetCode #142
Difficulty: Medium 

Approach:
1. Use the slow and the fast pointer approach to detect cycle.
2. If cycle has been detected, set the slow pointer to the head node.
3. Move both the pointers by one step until they collide at the starting point.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast= head;
        ListNode* slow= head;

        while (fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
            if (slow==fast){
                slow= head;
                while (slow!=fast){
                    slow= slow->next;
                    fast= fast->next;
                }
                return slow;
            }
        }
        return nullptr;        
    }
};
