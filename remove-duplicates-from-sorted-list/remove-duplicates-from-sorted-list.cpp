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
        ListNode* fake = head;
        while(fake && fake->next)
        {
            if(fake->next->val == fake->val)
            {
                fake->next=fake->next->next;
            }
            else
            {
                fake=fake->next;
            }
        }
        return head;
    }
};