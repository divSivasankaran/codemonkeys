"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as:

    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


def has_cycle(head):
    # if no list or only single node, no cycle
    if head is None or head.next is None:
        return False
    else:
        if head.next.next is not None:
            p1 = Node()
            p2 = Node()
            # move p1 one node at a time, and p2 two nodes at a time
            p1 = head
            p2 = head.next.next
            if p1 == p2:
                return True
            count = 0
            status = False
            while(p1 and p2 and (count <= 100) ):
                p1 = p1.next
                p2 = p2.next.next
                count += 1
                if p1 == p2:
                    status = True
                    break
            return status
    pass
