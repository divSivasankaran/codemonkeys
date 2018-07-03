def groupingDishes(dishes):
    groupDishes = dict()
    for item in dishes:
        dish = item[0]
        # Adding the dish to the dictionary with the ingredient as key
        for ingredient in item[1:]:
            if ingredient not in groupDishes:
                groupDishes[ingredient] = []
            groupDishes[ingredient].append(dish)
    res = []
    # Sort the keys in alphabetical order
    for key in sorted(groupDishes.keys()):
        g  = groupDishes[key]
        # Only display items that are part of 2 or more dishes
        if len(g) >= 2:
            g = sorted(g)
            g.insert(0,key)
            res.append(g)
    return res
