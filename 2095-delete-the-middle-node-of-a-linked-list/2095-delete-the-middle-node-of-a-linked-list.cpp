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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next)
            return nullptr;
        
        ListNode* s = head;
        ListNode* f = head;
        
        int i = 0;
        
        while (f->next) {
            if (++i % 2 == 0 && i > 2)
                s = s->next;
            f = f->next;
        }
        
        cout << s->val << " " << i << endl;
        
        if (i % 2 == 0)
            s->next = s->next->next;
        else if (s->next->next)
            s->next->next = s->next->next->next;
        else if (s == head)
            s->next = nullptr;
        
        return head;
    }
};