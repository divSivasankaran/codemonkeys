# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def rearrangeLastN(l, n):
    if n == 0 or l == None:
        return l

    ptr,last,head,tail = l, None, l,None
    ndist = 0
    while ptr!=None:
        last = ptr
        if ndist == n:
            if head.next != None:
                tail = head
                head = head.next
            ndist -= 1
        ptr = ptr.next
        ndist += 1

    if tail != None:
        last.next = l
        tail.next = None
    return head
