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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode d = new ListNode(-1 , head);
        ListNode prevLeft=d, cur=head;
        int cnt=1;
        //move till left pos
        while(cnt < left){
            prevLeft = cur;
            cur = cur.next;
            cnt++;
        }

        //cur - start of left node , prevLeft - prev node of left node 
        ListNode prev = null;
        while(cnt <= right){
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
            cnt++;//
        }
        //prevLeft's left is old left node(before reverse)
        //
        prevLeft.next.next = cur;//point to node after right
        prevLeft.next = prev;  
        return d.next;
    }
}