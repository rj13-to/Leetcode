class Solution {
public:
    ListNode* merge(ListNode* l,ListNode* r){
        if(!l||!r)return !l?r:l;
        ListNode* m;
        if(l->val<r->val){
            m=l;
            m->next=merge(l->next,r);
        }
        else {
            m=r;
            m->next=merge(l,r->next);
        }
        return m;
    }
    ListNode* half(ListNode* x){
        ListNode * s=x,*f=x->next->next;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* m=half(head);
        ListNode* r=sortList(m->next);
        m->next=NULL;
        ListNode* l=sortList(head);
        return merge(l,r);
    }
};