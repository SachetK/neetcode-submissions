# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        temp = head
        
        while temp != None:
            temp = temp.next
            length += 1
        
        pos = 0
        curr, prev = head, None

        while pos < length - n and curr != None:
            prev = curr
            curr = curr.next
            pos += 1
        
        if prev != None:
            if curr != None: # Delete from the middle
                prev.next = curr.next
            else: # Delete from the end
                prev.next = None
        else: # Delete from the front
            head = head.next
        
        return head
