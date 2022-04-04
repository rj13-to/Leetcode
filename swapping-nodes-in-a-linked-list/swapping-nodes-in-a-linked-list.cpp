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
    ListNode* swapNodes(ListNode* head, int k) {
        int tot=0;
        ListNode* f=head,*z;
        while(f){tot++;if(tot==k) z=f;f=f->next;}
        f=head;
        tot-=k;
        while(tot){tot--;f=f->next;}
        swap(f->val,z->val);return head;
    }
};