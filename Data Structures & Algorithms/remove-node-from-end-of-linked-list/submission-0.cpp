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

int find_total(ListNode* head){
    int count=0;
    ListNode* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //nth node form the end is n-k th node from the start

        //find the total nodes
        int nodes=find_total(head);
        int from_start=nodes-n;

        if(from_start==0)return head->next;
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            if(count==from_start)temp->next=temp->next->next;
            temp=temp->next;
        }
        return head;
    }
};
