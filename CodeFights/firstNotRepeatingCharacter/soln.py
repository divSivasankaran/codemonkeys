def firstNotRepeatingCharacter(s):
    found = dict()  # Will hold at max, all the 26 alphabets => O(1) space
    nodup = '_'

    for i,c in enumerate(s): # We iterate through each character only once => O(n) time
        if c not in found:
            found[c] = (i+1)*2
        else: # found the character in dict
            found[c] = 0

    val = len(s)*2
    for c,v in found.items(): # At most 26 iterations => O(1) time
        if v != 0 and v <= val:
            nodup = c
            val = v
    return nodup
    
