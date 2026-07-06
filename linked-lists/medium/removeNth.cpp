/*
Problem: Remove the Nth node of the linked list
Platform: LeetCode #19
Difficulty: Medium 

Approach:
1. Reverse the list.
2. Delete the nth node.
3. Return head of reversed list.

Time Complexity: O(n)
Space Complexity: O(1)

Date Solved: 2026-07-06
*/

class Solution {
public:
    ListNode* reverseLinked(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseLinked(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return nullptr;

        ListNode* newHead = reverseLinked(head);

        ListNode* temp = newHead;
        ListNode* prev = nullptr;
        int count = 1;

        while (temp) {
            if (count == n) {
                if (prev == nullptr)
                    newHead = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                return reverseLinked(newHead);
            }

            prev = temp;
            temp = temp->next;
            count++;
        }

        return reverseLinked(newHead);
    }
};
