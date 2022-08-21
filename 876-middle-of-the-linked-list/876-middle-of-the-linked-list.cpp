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
    ListNode* middleNode(ListNode* head) {
        ListNode * left = head;
        ListNode * right = left;
        
        bool even = true;
        
        while (right->next) {
            right = right->next;
            if (even) {
                left = left->next;
            }
            even = !even;
        }
        
        return left;
    }
};