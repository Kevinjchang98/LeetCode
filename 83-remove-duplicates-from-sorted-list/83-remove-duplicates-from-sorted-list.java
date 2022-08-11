/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head;
        
        while(curr != null) {
            while (curr.next != null && curr.val == curr.next.val) {
                ListNode t = curr.next.next;
                
                curr.next = t;
            }
            
            curr = curr.next;
        }
        
        return head;
    }
}