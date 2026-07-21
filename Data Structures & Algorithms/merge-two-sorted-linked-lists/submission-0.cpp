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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        ListNode* merge=new ListNode(-1);
        ListNode* dummy=merge;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                merge->next=temp1;
                temp1=temp1->next;
            }
            else{
                merge->next=temp2;
                temp2=temp2->next;
            }
            merge=merge->next;
        }
        while(temp1){
            merge->next=temp1;
            merge=merge->next;
            temp1=temp1->next;
        }
        while(temp2){
            merge->next=temp2;
            merge=merge->next;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};
