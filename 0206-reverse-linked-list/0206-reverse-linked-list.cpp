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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* next = curr->next;
            // Flip the arrow direction
            curr->next = prev;
            // Move onto the next node
            prev = curr;
            curr = next;
        }
        // Return prev since it is last node of orginal list
        return prev;
    }

    // if there a child go int o child
    // then we flip our point to parent
    // return
};