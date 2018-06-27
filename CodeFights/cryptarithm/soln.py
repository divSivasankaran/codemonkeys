def convert2digits(crypt,soldict):
    if type(crypt) is list: # handling list/word in the same fn.
        res =[]
        for a in crypt:
            res.append(convert2digits(a,soldict))
        return res
    else:
        res = ""
        for c in crypt:
            res = res + soldict[c]
        res = int(res)
        if len(str(res)) != len(crypt): # checking for leading zeros
            res = -1
        return res

def isCryptSolution(crypt, solution):
    # Converting input to representations that are easier to manage
    soldict = dict(solution)
    # convert strings to corresponding crypt digits
    word1, word2, word3 = convert2digits(crypt,soldict)
    if word1 + word2 == word3:
         return True

    return False
