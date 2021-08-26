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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* f,*k=new ListNode();f=k;
        while(l1!=nullptr || l2!=nullptr){
            if(l1==nullptr){
                k->next=l2;
                l2=nullptr;
            }
            else if(l2==nullptr){
                k->next=l1;
                l1=nullptr;
            }
            else{
                if(l1->val<l2->val){
                    ListNode *z= new ListNode(l1->val);
                    k->next=z;
                    k=k->next;l1=l1->next;
                }else{
                    ListNode *z= new ListNode(l2->val);
                    k->next=z;
                    k=k->next;l2=l2->next;
                }
            }
        }return f->next;
    }
};