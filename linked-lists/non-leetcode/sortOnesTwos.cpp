/* 
Problem: Sort 0's, 1's and 2's in linked list
Approach: 
1. Create three linked lists storing the zero, one and two nodes respectively.
2. Iterate through the linked list.
3. When the single iteration is complete, connect the respective lists/
*/


/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            ListNode* temp= head;
            ListNode* oneHead= new ListNode(-1);
            ListNode* twoHead= new ListNode(-1);
            ListNode* zeroHead= new ListNode(-1);
            ListNode* zero= zeroHead;
            ListNode* one= oneHead;
            ListNode* two= twoHead;

            while(temp!=nullptr){
                if (temp->data==0){
                    zero->next= temp;
                    zero= zero->next;
                }
                else if (temp->data==1){
                    one->next= temp;
                    one= one->next;
                }
                else {
                    two->next= temp;
                    two= two->next;
                }
                temp= temp->next;
            }
            zero->next= (oneHead->next!=nullptr)? oneHead->next: twoHead->next;
            one->next= twoHead->next;
            two->next= nullptr;
            return zeroHead->next;
        }
};
