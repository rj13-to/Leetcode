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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* odd  = head;
        ListNode* even = head->next,*k;
        k=even;
        while(even && even->next)
        {
            head->next=even->next;
            head=head->next;
            even->next=head->next;
            even=even->next;
        }
        head->next=k;
        return odd;
    }
};