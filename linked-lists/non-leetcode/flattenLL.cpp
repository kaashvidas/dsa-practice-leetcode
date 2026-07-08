/* 
Problem: Flattening of Linked List
Approach: 
1. Define a merge function for merging two sorted vertical lists.
2. Call the recursive function for merging the entire list.

Time Complexity: O(2NM)
Space Complexity: O(N)
*/


/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy= new ListNode(-1);
        ListNode* res= dummy;
        while (list1!=nullptr && list2!=nullptr){
            if (list1->val<list2->val){
                res->child= list1;
                res=list1;
                list1= list1->child;
            }
            else {
                res->child= list2;
                res=list2;
                list2=list2->child;
            }
            res->next= nullptr;
        }
        if (list1!=nullptr){
            res->child= list1;
            res= list1;
        }
        else if (list2!=nullptr){
            res->child=list2;
            res=list2;
        }
        if (dummy->child){
            dummy->child->next= nullptr;
        }
        return dummy->child;
    }
    ListNode* flattenLinkedList(ListNode* &head) {
        if (head==nullptr|| head->next==nullptr){
            return head;
        }
        ListNode* mergedHead= flattenLinkedList(head->next);
        head= merge(head, mergedHead);
        return head;
    }
};
