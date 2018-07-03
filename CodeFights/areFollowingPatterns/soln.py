# O(n) space and O(n) time
def areFollowingPatterns(strings, patterns):
    # maintain two hash maps with strings and patterns as keys, value and vice versa.
    stringhash = dict()
    patternhash = dict()
    for s,p in zip(strings,patterns):
        if p not in patternhash.keys():
            patternhash[p] = s
        elif patternhash[p] != s : # key p already exists, check if string matches
            return False

        if s not in stringhash.keys():
            stringhash[s] = p
        elif stringhash[s] != p: # key s already exists, check if pattern matches
            return False
    return True
