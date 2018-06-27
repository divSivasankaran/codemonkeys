import numpy as np
def firstDuplicate(a):
    # Store all elements you see in a set
    exists = set()
    for i,elem in enumerate(a):
        if elem == ".":
            continue
        elif int(elem) <1 or int(elem) >9:
            return 10
        # If it doesn't exist yet, make note of it
        if elem not in exists:
            exists.add(elem)
        else: # It already exists! Aha! we've found the first duplicate!
            return elem
    return -1


def sudoku2(grid):
    grid = np.array(grid)
    # Check repetitions in rows
    for r in range(0,len(grid)):
        res = firstDuplicate(grid[r])
        if res!= -1:
            print("rows ", r, " ", res)
            return False
    # Check repetitions in columns
    for c in range(0,len(grid[0])):
        res = firstDuplicate(grid[:,c])
        if res!= -1:
            print("col ", c, " ", res)
            return False
    # Check repetitions in 3x3 grids
    for r in range(0,len(grid), 3):
        for c in range(0, len(grid[r]), 3):
            lst = grid[r:r+3,c:c+3].flatten()
            res = firstDuplicate(lst)
            if res!= -1:
                print("col ", c, " ", res)
                return False
    return True
