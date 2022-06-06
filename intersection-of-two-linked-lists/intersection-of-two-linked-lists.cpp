/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0;int b=0;
        ListNode* tempa,*tempb;
        tempa=headA;tempb=headB;
        while(tempa!=nullptr){a++;tempa=tempa->next;}
        while(tempb!=nullptr){b++;tempb=tempb->next;}
        tempa=headA;tempb=headB;
        while(a>b){
            a--;tempa=tempa->next;
        }
        while(b>a){
            b--;tempb=tempb->next;
        }
        while(a){
            if(tempa==tempb)break;
            a--;
            tempa=tempa->next;tempb=tempb->next;
        }return tempa;
    }
};