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
    ListNode* middleNode(ListNode* head) {
        ListNode* f=head;
        int tot=0;
        while(f!=nullptr){tot++;f=f->next;}
        tot/=2;
        while(tot){
            head=head->next;tot--;
        }return head;
    }
};