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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        auto comp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        
        bool empty = false;
        
        while (!empty) {
            empty = true;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    empty = false;
                    ListNode* curr = lists[i];
                    q.push(curr);
                    lists[i] = lists[i]->next;
                    curr->next = nullptr;
                }
                
            }
        }
        
        if (q.size() == 0)
            return nullptr;
        
        ListNode* curr = q.top();
        ListNode* ans = curr;
        q.pop();
        
        while (!q.empty()) {
            curr->next = q.top();
            curr = curr->next;
            q.pop();
        }
        
        return ans;
    }
};