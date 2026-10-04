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
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int num1 = (l1 != nullptr) ? l1->val: 0;
            int num2 = (l2 != nullptr)? l2->val: 0;

            int digit = num1 + num2 + carry;
            carry = digit / 10;
            int result = digit % 10;
            
            head->next = new ListNode(result);
            head = head->next;
            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};
