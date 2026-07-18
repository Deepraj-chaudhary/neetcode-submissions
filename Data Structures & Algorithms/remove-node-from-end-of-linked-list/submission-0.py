# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        prev = None
        curr = head 
        while curr:
            t = curr.next
            curr.next=prev
            prev = curr 
            curr = t
        ans = prev
        prev1 = None
        while n-1:
            prev1= ans
            ans = ans.next
            n-=1

        if prev1:
            prev1.next = ans.next
            ans.next = None
        else:
            prev = ans.next
            ans.next = None

        curr = prev
        prev = None
        while curr:
            t = curr.next
            curr.next=prev
            prev = curr 
            curr = t

        return prev
        

        


