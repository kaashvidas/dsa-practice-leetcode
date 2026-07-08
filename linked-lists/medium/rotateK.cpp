/*
Problem: Rotate right by k
Platform: LeetCode #61
Difficulty: Medium 

Approach:
1. Count the nodes and traverse to the (n-k)th node.
2. Break after the (n-k) node.
3. Connect the last node to the original head.

Time Complexity: O(2n)
Space Complexity: O(1)

Date Solved: 2026-07-08
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
    int countNodes(ListNode* head){
        int count=0;
        ListNode* temp= head;
        while (temp!=nullptr){
            count++;
            temp= temp->next;
        }
        return count;
    }
    ListNode* findK(ListNode* head, int k){
        k=k-1;
        ListNode* temp= head;
        while (temp!=nullptr && k>0){
            k--;
            temp= temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        int n= countNodes(head);
        k=k%n;
        if (k==0){
            return head;
        }
        else {
            ListNode* kNode= findK(head, n-k);
            ListNode* newHead= kNode->next;
            ListNode* last= newHead;
            while (last->next!=nullptr){
                last= last->next;
            }
            kNode->next=nullptr;
            last->next= head;
            head= newHead;
            return head;
        }
        
    }
};
