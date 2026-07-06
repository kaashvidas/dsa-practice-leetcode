/*
Problem: Intersection of two linked lists 
Platform: LeetCode #160
Difficulty: Easy

Approach:
1. Maintain pointers for both the lists and increment it by one at each step.
2. If any of the pointers becomes null before the other, reset it to the head of the other list.
3. Do this until the two pointers collide or if both become null.

Time Complexity: O(n1+n2)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp= headA;
        ListNode* temp_2= headB;

        while (temp!=temp_2){
            temp= (temp==nullptr)? headB: temp->next;
            temp_2= (temp_2==nullptr)? headA: temp_2->next;
        }
        return temp;
    }
};
