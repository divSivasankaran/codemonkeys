""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""
#max left subtree and min right sub tree
flag=True
def inOrder(root):
    global flag

    if root:
        maxx=root.data
        minn=root.data
        lefts=inOrder(root.left)
        if lefts:
            if lefts[0] >= root.data:                
                flag=False
            maxx=max(lefts[0],root.data)
            minn=min(lefts[1],root.data)
        rights=inOrder(root.right)

        if rights:
            if rights[1] <= root.data:                
                flag=False
            maxx=max(maxx,rights[0])
            minn=min(minn,rights[1])
        return [maxx,minn]
    return None
            
def checkBST(root):
    global flag
    inOrder(root)
    return flag
