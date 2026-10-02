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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the LL
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(second != nullptr){
            ListNode* next = second->next;

            second->next = prev;

            prev = second;
            second = next;
        }

        second = prev;
        ListNode* first = head;

        while(second != nullptr){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        } 

    }
};
