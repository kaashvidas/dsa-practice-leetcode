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
    ListNode* findK(int k, ListNode* temp){
        k= k-1;
        while(temp!=nullptr && k>0){
            k--;
            temp= temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        if (head==nullptr || head->next== nullptr){
            return head;
        }
        ListNode* newHead= reverse(head->next);
        ListNode* front= head->next;
        front->next= head;
        head->next= nullptr;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp= head;
        ListNode* prev= nullptr;
        while (temp){
            ListNode* kNode= findK(k, temp);
            if (kNode==nullptr){
                if (prev){
                    prev->next= temp;
                    break;
                }
            }
            ListNode* nextNode= kNode->next;
            kNode->next= nullptr;
            reverse(temp);
            if (temp==head){
                head= kNode;
            }
            else {
                prev->next= kNode;
            }
            prev= temp;
            temp= nextNode;


        }
        return head;
        
    }
};
