/* 
Problem: Add one to the number in a linked list
Approach: 
1. Use Recursion for optimal solution. 
2. In the recursion function return carry at every call.
3. If carry is one till the end, add a new node at the head.
*/

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int helper(ListNode* temp){
        if (temp==nullptr){
            return 1;
        }
        int carry= helper(temp->next);
        temp->val = temp->val+ carry;
        if (temp->val< 10){
            return 0;
        }
        temp->val=0;
        return 1;
    }
    ListNode *addOne(ListNode *head) {
        int carry= helper(head);
        if (carry==1){
            ListNode* node= new ListNode(1, head);
            return node;
        }
        return head;
    }
};
