/*
Problem: Remove Linked List Elements 
Platform: LeetCode #203
Difficulty: Easy

Approach:
1. Create a dummy node.
2. Iterate through the linked list and for every node compare the value with the given value, if it matches assign temp, move forward and free temp.
3. Free the dummy node and return the next node as the head.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-04
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy= new ListNode(0);
        dummy->next= head;

        ListNode* curr= dummy;

        while (curr->next!=nullptr){
            if (curr->next->val==val){
                ListNode* temp= curr->next;
                curr->next= curr->next->next;
                delete temp;
            }
            else {
                curr= curr->next;
            }
        }
        ListNode* ans= dummy->next;
        delete dummy;
        return ans;        
    }
};
