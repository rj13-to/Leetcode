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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>>pq;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i] != nullptr)
            {
                pq.push({-lists[i]->val,i});
            }
        }
        while(pq.size())
        {
            pair<int,int> pr = pq.top();
            pq.pop();
            if(head == nullptr)
            {
                head = lists[pr.second];
                cur = lists[pr.second];
            }
            else
            {
                cur->next = lists[pr.second];
                cur = cur->next;
            }
            lists[pr.second] = lists[pr.second]->next;
            
            if(lists[pr.second] != nullptr)
            {
                pq.push({-lists[pr.second]->val,pr.second});
            }
        }
        return head;
    }
};