# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def mergeTwoLinkedLists(l1, l2):
    res = None
    ptr = res
    while(l1!=None and l2!=None):
        # While there are still elements in both lists, add the smaller one first
        if l1.value < l2.value:
            t = ListNode(l1.value)
            l1 = l1.next
        else:
            t = ListNode(l2.value)
            l2 = l2.next
        if res == None:
            res, ptr = t,t
        else:
            ptr.next, ptr = t, t
    # Handle cases where linked list sizes do not match. In this case, we just have to append the rest of the list 
    while(l1!=None):
        t = ListNode(l1.value)
        l1 = l1.next
        if res == None:
            res, ptr = t,t
        else:
            ptr.next, ptr = t, t

    while(l2!=None):
        t = ListNode(l2.value)
        l2 = l2.next
        if res == None:
            res, ptr = t,t
        else:
            ptr.next, ptr = t, t

    return res
