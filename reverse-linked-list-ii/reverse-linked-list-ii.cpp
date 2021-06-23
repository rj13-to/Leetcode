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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode* f=head;
        while(f)
        {
            v.push_back(f->val);
            f=f->next;
        }
        left--;
        reverse(v.begin()+left,v.begin()+right);
        f=head;
        int i=0;
        while(f)
        {
            f->val=v[i];
            i++;
            f=f->next;
        }return head;
    }
};