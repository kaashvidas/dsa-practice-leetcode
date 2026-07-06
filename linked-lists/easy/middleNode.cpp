/*
Problem: Middle Node of the Linked List
Platform: LeetCode #876
Difficulty: Easy

Approach:
1. Use the Tortoise-Hare method (slow and fast pointer).
2. Two pointers start by pointing at head, at each step slow moves by one step while fast moves by two steps.
3. When fast reaches null or thr last node, slow reaches the middle node and is returned.

Time Complexity: O(n/2)
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast= head;
        ListNode* slow= head;

        while (fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }

        return slow;        
    }
};
