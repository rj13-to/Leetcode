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
    ListNode* deleteDuplicates(ListNode* head) {
       map<int,int>mp;
        while(head!=nullptr){
            mp[(head->val)]++;
            head=head->next;
        }
        ListNode *n=new ListNode(),*f;
        f=n;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>1) continue;
            ListNode* z = new ListNode(it->first);
            f->next=z;
            f=f->next;
        }
        n=n->next;
        return n;
    }
};