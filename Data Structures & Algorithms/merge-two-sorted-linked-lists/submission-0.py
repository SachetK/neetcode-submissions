# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        
        if not list2:
            return list1
        
        merged = ListNode(list1.val) if list1.val < list2.val else ListNode(list2.val)
        
        if list1.val < list2.val:
            list1 = list1.next
        else:
            list2 = list2.next

        merged_head = merged

        while list1 and list2:
            if list1.val < list2.val:
                merged.next = ListNode(list1.val)
                list1 = list1.next
            else:
                merged.next = ListNode(list2.val)
                list2 = list2.next
            
            merged = merged.next
        
        if list1 and not list2:
            merged.next = list1
        
        if list2 and not list1:
            merged.next = list2
        
        return merged_head