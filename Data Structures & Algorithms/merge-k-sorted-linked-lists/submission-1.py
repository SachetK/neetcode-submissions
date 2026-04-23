# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeLists(list1, list2):
            if not list1:
                return list2
            
            if not list2:
                return list1

            merged = list1 if list1.val < list2.val else list2
            
            if list1.val < list2.val:
                list1 = list1.next
            else:
                list2 = list2.next

            merged_h = merged

            while list1 != None and list2 != None:
                if list1.val < list2.val:
                    merged.next = list1
                    list1 = list1.next
                else:
                    merged.next = list2
                    list2 = list2.next
                
                merged = merged.next
            
            if list1:
                merged.next = list1
            
            if list2:
                merged.next = list2
            
            return merged_h
        
        for i in range(len(lists) - 1):
            merged = mergeLists(lists[i], lists[i + 1])
            lists[i+1] = merged

        return lists[-1] if len(lists) > 0 else None