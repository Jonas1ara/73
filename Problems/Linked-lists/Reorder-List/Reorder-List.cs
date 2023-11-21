﻿/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    private int GetLength(ListNode head)
    {
        int ans = 0;
        for (ListNode current = head; current != null; current = current.next)
        {
            ans++;
        }
        return ans;
    }

    private ListNode SplitList(ListNode head)
    {
        int len = (GetLength(head) - 1) / 2;
        while (len > 0)
        {
            head = head.next;
            len--;
        }
        ListNode ans = head.next;
        head.next = null;
        return ans;
    }

    private ListNode ReverseList(ListNode head)
    {
        ListNode dummy = null;
        while (head != null)
        {
            ListNode node = head;
            head = head.next;
            node.next = dummy;
            dummy = node;
        }
        return dummy;
    }

    private void Interleave(ListNode first, ListNode second)
    {
        while (second != null)
        {
            ListNode node = second;
            second = second.next;
            node.next = first.next;
            first.next = node;
            first = node.next;
        }
    }

    public void ReorderList(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return;
        }

        ListNode second = SplitList(head);
        second = ReverseList(second);
        Interleave(head, second);
    }
}