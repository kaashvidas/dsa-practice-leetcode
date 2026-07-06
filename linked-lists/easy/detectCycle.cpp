/*
Problem: Linked List Cycle 
Platform: LeetCode #141
Difficulty: Easy

Approach:
1. Use the Tortoise- Hare approach using slow and fast pointers.
2. The slow pointer incremenets by one while the fast one increments by two.
3. If there is a loop in the linked list, the slow and the fast pointer collide at some point.

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
    bool hasCycle(ListNode *head) {
        ListNode* fast= head;
        ListNode* slow= head;

        while (fast!=nullptr && fast->next!=nullptr){
           
            slow= slow->next;
            fast= fast->next->next;
             if (slow==fast){
                return true;
            }
        }
        return false;
        
    }
};
