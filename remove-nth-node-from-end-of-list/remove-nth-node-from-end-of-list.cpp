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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot=0;
        ListNode* f=head;
        while(f){tot++;f=f->next;}
        tot-=n;
        if(tot==0) return head->next;
        f=head;
        tot--;
        while(tot){
            tot--;
            f=f->next;
        }f->next=(f->next)->next;return head;
    }
};