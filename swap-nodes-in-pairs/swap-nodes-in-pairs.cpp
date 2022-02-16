class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        vector<int>v;
        ListNode* p;
        ListNode* f;
        p=head;f=p;
        while(p!=nullptr){
            v.push_back(p->val);
            p=p->next;
        }
        for(int i=1;i<v.size();i+=2){
            swap(v[i],v[i-1]);
        }
        int i=0;
        while(head!=nullptr){
            head->val=v[i];i++;
            head=head->next;
        }head=f;
        return head;
    }
};