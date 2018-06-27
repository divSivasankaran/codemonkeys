def firstDuplicate(a):
    # Store all elements you see in a set
    exists = set()
    for i,elem in enumerate(a):
        # If it doesn't exist yet, make note of it
        if elem not in exists:
            exists.add(elem)
        else: # It already exists! Aha! we've found the first duplicate!
            return elem
    return -1
