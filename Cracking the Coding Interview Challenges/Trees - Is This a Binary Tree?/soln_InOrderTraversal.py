""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

# traverse binary tree in order
# check whether the elements are sorted after traversal

treeArray = []

def checkBST(root):
    traverseInOrder(root)

    for i in range(len(treeArray)-1):
        # if current number is larger than next number, it means the array is not in order
        if treeArray[i] >= treeArray[i+1]:
            return False
    return True

def traverseInOrder(root):
    if root:
        if root.left:
            traverseInOrder(root.left)
        treeArray.append(root.data)
        if root.right:
            traverseInOrder(root.right)
