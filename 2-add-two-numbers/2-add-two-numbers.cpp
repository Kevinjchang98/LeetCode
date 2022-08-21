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
        ListNode* ans = nullptr;
        ListNode* head = nullptr;
        int carry = 0;
        
        while (l1 && l2) {
            if (!ans) {
                ans = new ListNode((l1->val + l2->val) % 10);
                carry = (l1->val + l2->val + carry) / 10;
                head = ans;
            } else {
                ans->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
                ans = ans->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* temp = l1 ? l1 : l2;
        while (temp) {
            ans->next = new ListNode((temp->val + carry) % 10);
            carry = (temp->val + carry) / 10;
            temp = temp->next;
            ans = ans->next;
        }
        
        if (carry != 0)
            ans->next = new ListNode(carry);
        
        return head;
    }
    
};