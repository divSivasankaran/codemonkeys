# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def reverseNodesInKGroups(l, k):
    if k == 1:
        return l
    if l == None:
        return None
    ptr,prev = l,None
    kcounter,head = k,None

    # reverse list until k elements
    while kcounter != 0 and ptr != None:
        t = ptr.next
        head,ptr.next,prev,ptr  = ptr, prev, ptr, t
        kcounter -= 1

    # reverse these nodes again since there weren't enough.
    # I know, it's sad :(
    if kcounter != 0:
       return reverseNodesInKGroups(head, k-kcounter)

    # recursively call groups of k to be appended to the end of the list
    l.next = reverseNodesInKGroups(ptr,k)
    return head
