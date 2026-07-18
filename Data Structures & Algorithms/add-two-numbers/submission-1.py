# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        t1,prev1 = l1,l1
        t2,prev2 = l2,l2
        ans = 0
        m,n=0,0
        carry = 0
        while t1 or t2:
            temp = carry + (t1.val if t1 else 0) + (t2.val if t2 else 0)

            if temp>9:
                carry = 1
                temp = temp % 10
            else:
                carry = 0

            
            if t1:
                prev1 = t1
                t1.val = temp
                t1 = t1.next
                m+=1
                
            if t2:
                prev2 = t2
                t2.val = temp
                t2 = t2.next
                n+=1

        if m>=n:
            if carry:
                prev1.next = ListNode(1)
            return l1
        else:
            if carry:
                prev2.next = ListNode(1)
            return l2


            