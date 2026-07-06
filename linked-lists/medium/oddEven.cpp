/*
Problem: Odd and Even Linked List Nodes 
Platform: LeetCode #328
Difficulty: Medium 

Approach:
1. Change the links by skipping nodes.
2. Connect the last odd node to head of even nodes.

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
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* odd= head;
        ListNode* even= head->next;
        ListNode* evenHead= head->next;

        while (even && even->next){
            odd->next= odd->next->next;
            even->next= even->next->next;
            odd=odd->next;
            even= even->next;
        } 
        
        odd->next= evenHead;
        return head;     
    }
};
