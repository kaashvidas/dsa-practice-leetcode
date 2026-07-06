/*
Problem: Palindrome Linked List
Platform: LeetCode #234
Difficulty: Easy

Approach:
1. Use the fast and slow pointer to reach the middle node of the linked list.
2. Reverse the second half of the linked list.
3. Compare the first half and second half.

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
    ListNode* reverseLinked(ListNode* head){
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newHead= reverseLinked(head->next);
        ListNode* front= head->next;
        front->next= head;
        head->next= nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head==nullptr){
            return true;
        }
        ListNode* slow= head;
        ListNode* fast= head;

        while (fast->next!=nullptr && fast->next->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }

        ListNode* newHead= reverseLinked(slow->next);
        ListNode* first= head;
        ListNode* second= newHead;

        while (second!=nullptr){
            if (first->val!= second->val)
            {
                reverseLinked(newHead);
                return false;
            }
            first= first->next;
            second= second->next;
        }
        reverseLinked(newHead);
        return true;
        
    }
};
