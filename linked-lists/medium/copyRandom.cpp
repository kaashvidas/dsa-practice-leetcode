/*
Problem: Copy List with Random Pointer
Platform: LeetCode #138
Difficulty: Medium 

Approach:
1. Create and insert copy nodes in between the original list.
2. Assign the random pointers.
3. Assign the next pointers and separate the clone and original lists.

Time Complexity: O(3n)
Space Complexity: O(1)

Date Solved: 2026-07-08
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr){
            return nullptr;
        }
        Node* temp= head;
        while(temp!=nullptr){
            Node* copyNode= new Node(temp->val);
            copyNode->next= temp->next;
            temp->next= copyNode;
            temp= temp->next->next;
        }

        temp= head;
        while(temp!=nullptr){
            Node* copyNode= temp->next;
            copyNode->random= (temp->random)?temp->random->next: nullptr;
            temp= temp->next->next;
        }

        temp= head;
        Node* dummy= new Node(-1);
        Node* res= dummy;
        while(temp!=nullptr){
            res->next= temp->next;
            temp->next= temp->next->next;
            res= res->next;
            temp= temp->next;
        }
        return dummy->next;
        
    }
};
