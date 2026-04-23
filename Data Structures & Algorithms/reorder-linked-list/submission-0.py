# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        N = 0
        temp = head
        while temp != None:
            temp = temp.next
            N += 1
        
        mid = N // 2
        temp = head
        
        # Find midpoint
        for _ in range(mid):
            temp = temp.next
        
        # Reverse second half
        prev, curr = None, temp

        while curr != None:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        dummy = ListNode()
        merged = dummy
        
        # Merge
        for i in range(N):
            if i % 2 == 0:
                merged.next = head
                head = head.next
            else:
                merged.next = prev
                prev = prev.next

            merged = merged.next

        head = dummy.next

        

        
        
        