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

ListNode* reverse(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode* middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // First middle
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        ListNode* mid = middle(head);

        ListNode* right_half = reverse(mid->next);
        mid->next = nullptr;

        ListNode* left_half = head;

        ListNode dummy(-1);
        ListNode* newhead = &dummy;

        int count = 0;

        while (left_half && right_half) {

            if (count % 2 == 0) {
                newhead->next = left_half;
                left_half = left_half->next;
            } else {
                newhead->next = right_half;
                right_half = right_half->next;
            }

            newhead = newhead->next;
            count++;
        }

        while (left_half) {
            newhead->next = left_half;
            left_half = left_half->next;
            newhead = newhead->next;
        }

        while (right_half) {
            newhead->next = right_half;
            right_half = right_half->next;
            newhead = newhead->next;
        }

        newhead->next = nullptr;
    }
};