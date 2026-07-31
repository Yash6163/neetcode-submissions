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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        dummy->next=ans;
        while(temp1 && temp2){
            int val=(temp1->val+temp2->val+carry)%10;
            carry=(temp1->val+temp2->val+carry)/10;
            temp1=temp1->next;
            temp2=temp2->next;
            ans->next=new ListNode(val);
            ans=ans->next;
        }
        while(temp1){
            ans->next=new ListNode((temp1->val+carry)%10);
            carry=(temp1->val+carry)/10;
            temp1=temp1->next;
            ans=ans->next;
        }
        while(temp2){
            ans->next=new ListNode((temp2->val+carry)%10);
            carry=(temp2->val+carry)/10;
            temp2=temp2->next;
            ans=ans->next;
        }
        if(carry){
            ans->next=new ListNode(carry);
            ans=ans->next;
        }
        return dummy->next;
    }
};
