/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* res = nullptr;
    Node* crr = nullptr;
    void fun(Node* head)
    {
        if(head == nullptr) return ;
        if(crr)
        {
            crr->next = head;
            head->prev = crr;
            crr = crr->next;
        }
        else
        {
            res = head;
            crr = res;
        }
        Node* next=head->next,*child=head->child;
        head->next = head->child = nullptr;
        if(child)
        {
            fun(child);
        }
        fun(next);
    }
    Node* flatten(Node* head) 
    {
        fun(head);
        
        return res;
    }
};