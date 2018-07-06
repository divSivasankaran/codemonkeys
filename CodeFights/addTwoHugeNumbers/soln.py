# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#

def addnums(a,b,c=0):
    t = int(a.value) + int(b.value) + c
    if len(str(t)) > 4:
        carry,val = str(t)[0:-4],str(t)[-4:]
    else:
        carry = 0
        val = t
    return int(carry),int(val)


def addTwoHugeNumbers(a, b, res = None):

    # Reverse the lists
    aptr,ptr1 = a,a
    bptr,ptr2 = b,b
    aprev, bprev = None,None

    #reverse links
    while(ptr1!=None or ptr2!=None):
        if ptr1 != None:
            aptr = ptr1
            t = ptr1.next
            ptr1.next = aprev
            aprev = ptr1
            ptr1 = t
        if ptr2 != None:
            bptr = ptr2
            t = ptr2.next
            ptr2.next = bprev
            bprev = ptr2
            ptr2 = t

    # Add the numbers together one node at a time
    res = None
    carry = 0
    while(aptr!=None and bptr!=None):
        carry, val = addnums(aptr, bptr, carry)

        t = ListNode(val)
        t.next = res
        res = t

        aptr = aptr.next
        bptr = bptr.next

    # Handle unequal sizes by ensuring there aren't any nodes left in a
    while(aptr!=None):
        carry, val = addnums(aptr, ListNode(0), carry)

        t = ListNode(val)
        t.next = res
        res = t
        aptr = aptr.next

    # Handle unequal sizes by ensuring there aren't any nodes left in b
    while(bptr!=None):
        carry, val = addnums(bptr, ListNode(0), carry)

        t = ListNode(val)
        t.next = res
        res = t
        bptr = bptr.next

    # Add on the carry over to a new linkedlist if it is not 0
    if carry != 0:
        t = ListNode(carry)
        t.next = res
        res = t

    return res
        
