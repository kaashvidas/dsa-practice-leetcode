/*
Problem: Reverse Linked List 2 
Platform: LeetCode #92
Difficulty: Medium 

Approach:
1. Move to one node before the left node and store it as prev.
2. Instead of iterating, perform (right-left) number of reversals.
3. Create dummy node before head node to cover edge cases.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if (head==nullptr || right==left|| head->next==nullptr){
        return head;
       }

       ListNode* dummy= new ListNode(0, head);
       ListNode* prev= dummy;

       for (int i=1; i<left; i++){
        prev= prev->next;
       }
       ListNode* curr= prev->next;

       for (int i=0; i< right-left; i++){
        ListNode* temp= curr->next;
        curr->next= temp->next;
        temp->next= prev->next;
        prev->next= temp;
       }

       return dummy->next;
        
    }
};
