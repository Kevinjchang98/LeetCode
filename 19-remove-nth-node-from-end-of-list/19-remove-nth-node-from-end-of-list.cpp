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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            return nullptr;
        }
        
        ListNode* left = head;
        ListNode* right = left;
        
        for (int i = 0; i < n; i++) {
            if (right->next) {
                right = right->next;
            } else {
                head = left->next;
                return head;
            }
        }
        
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        
        if (left->next) {
            if (left->next->next) {
                left->next = left->next->next;
            } else {
                left->next = nullptr;
            }
        }
        
        return head;
    }
};