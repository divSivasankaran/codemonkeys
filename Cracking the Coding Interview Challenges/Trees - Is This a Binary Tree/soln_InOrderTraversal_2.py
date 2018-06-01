""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""
array=[]
def inOrder(root):
    global array
    if root:
        inOrder(root.left)
        array.append(root.data)
        inOrder(root.right)
def checkBST(root):
    inOrder(root)
    for i in range(0,len(array)-1):
        if array[i] >= array[i+1]:
            return False
    return True
