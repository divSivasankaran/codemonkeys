def containsDuplicates(a):

    items = set()
    for elem in a:
        if elem not in items:
            items.add(elem)
        else:
            return True
    return False
