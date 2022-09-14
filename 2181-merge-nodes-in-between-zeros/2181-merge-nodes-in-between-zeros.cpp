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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* t = head;
        
        while (f->next && f->next->val != 0) {
            int curr = 0;
            f = f->next;
            
            while (f->val != 0) {
                curr += f->val;
                f = f->next;
            }
            
            s->val = curr;
            s->next = f;
            t = s;
            s = s->next;
            f = s;
        }
        
        t->next = nullptr;
        
        return head;
    }
};