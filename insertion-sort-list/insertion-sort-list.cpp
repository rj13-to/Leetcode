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
    ListNode* insertionSortList(ListNode* head) 
    {
        vector<int>v;
        ListNode* f = head;
        
        while(f) 
        {
            v.push_back(f->val);
            f= f-> next;
        }
        
        sort(v.begin(),v.end());
        f  = head;
        for(int i=0;i<v.size();i++)
        {
            f->val = v[i];
            f= f->next;
        }
        return head;
    }
};