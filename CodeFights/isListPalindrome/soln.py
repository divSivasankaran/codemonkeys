# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def isListPalindrome(l):

    if l is None:
        return True

    count = 0
    doubleptr = l
    midptr = l
    midpt_prev = None

    # O(logn) Time
    while(doubleptr!=None and doubleptr.next != None):
        doubleptr = doubleptr.next.next
        if(midptr.next != None):
            midpt_prev = midptr
            midptr = midptr.next
        count += 2

    if(doubleptr!=None):
        count += 1

    # Reverse half the list,  O(n) time
    last = midptr
    ptr = midptr
    prev = None
    while(ptr!=None):
        last = ptr
        #reverse links
        t = ptr.next
        ptr.next = prev
        prev = ptr
        ptr = t

    if(count%2 == 0 and midpt_prev!= None):
        midpt_prev.next = None
    elif count %2 == 1 and midptr !=None:
        midptr.next = None

    # O(n) time
    # Compare the two half-lists
    lptr = l
    rptr = last
    while(lptr!=None and rptr!=None):
        if(lptr.value != rptr.value):
            return False
        lptr = lptr.next
        rptr = rptr.next

    return True
