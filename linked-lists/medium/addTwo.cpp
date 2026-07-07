/*
Problem:Add Two Numbers 
Platform: LeetCode #2
Difficulty: Medium 

Approach:
1. Iterate through both the linked lists and store their sum and carry at each step into a new list.

Time Complexity: O(n1+n2)
Space Complexity: O(n)

Date Solved: 2026-07-07
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* curr= dummy;
        int carry=0;
        while (l1||l2||carry){
            int sum= carry;
            if (l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2){
                sum+=l2->val;
                l2=l2->next;
            }
            curr->next= new ListNode(sum%10);
            carry= sum/10;
            curr=curr->next;
        }
        return dummy->next;
        
    }
};
