/*
Problem: Reverse the Linked List
Platform: LeetCode #206
Difficulty: Easy

Approach:
1. Maintain three pointers- prev, curr and next1. 
2. Iterate through and reverse the links.
3. Return the last node as the head node.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-05
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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr){
            return nullptr;
        }
        if (head->next== nullptr){
            return head;
        }

        ListNode* curr= head;
        ListNode* prev= nullptr;
        ListNode* next1;

        while(curr!=nullptr){
            next1= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next1;
        }
        head= prev;
        return head;        
    }
};
