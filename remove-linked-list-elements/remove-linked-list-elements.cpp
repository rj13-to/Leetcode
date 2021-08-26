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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* f=new ListNode(),*k;k=f;
        while(head){
            if(head->val!=val){
            ListNode* z=new ListNode(head->val);
            f->next=z;
            f=f->next;}head=head->next;
        }
        return k->next;
    }
};