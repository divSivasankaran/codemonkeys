# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def removeKFromList(l, k):

    # We don't store anything other than prev and ptr => O(1) space
    ptr = l
    prev = None

    # We iterate through each node in the linkedlist only once. => O(n) time
    while ptr is not None:
        if ptr.value == k:
            # We must associate the prev node to the next node, effectively skipping this node
            if prev is not None:
                prev.next = ptr.next
            else: # in the event that prev is empty, it means ptr is at the head of the list, therefore change the head l
                l = ptr.next
        else:
            # update prev if it doesn't contain the value k
            prev = ptr
        ptr = ptr.next

    return l
