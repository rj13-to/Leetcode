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
    void reorderList(ListNode* head) 
    {
        vector<int>v;
        ListNode* f = head;
        while(f)
        {
            v.push_back(f->val);
            f=f->next;
        }
        f= head;
        int i=0,j=v.size()-1;
        while(i <= j)
        {
            f->val = v[i];
            i++;
            f=f->next;
            if(i<=j)
            {
                f->val =v[j];
                j--;
                f=f->next;
            }
        
        }    
    }
};