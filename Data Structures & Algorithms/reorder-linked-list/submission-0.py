# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        last = head
        cnt = 0
        while last:
            last = last.next   
            cnt += 1
        half = (cnt+1)//2-1

        l2=head
        while half:
            l2=l2.next
            half-=1
        t = l2.next
        l2.next,l2 = None, t
        l1 = head
        prev = None 
        curr = t
        while curr:
            t2 = curr.next
            curr.next = prev
            prev = curr
            curr = t2

        l2 = prev
        
        while l2:
            t1 = l1.next
            t2 = l2.next
            l1.next = l2
            l2.next = t1
            l2 = t2 
            l1 = t1
        
        



        