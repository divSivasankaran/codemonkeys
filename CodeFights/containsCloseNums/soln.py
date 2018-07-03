# O(n) time and O(n) space
def containsCloseNums(nums, k):
    # dictionary to hold information about the last_seen index for each number in the list
    num_map = dict()
    for i, n in enumerate(nums):
        if n in num_map.keys():
            # If the last seen of this number n is <=k away from the current index then return true
            if abs(num_map[n] - i) <= k:
                return True
        # update last seen index to the current one
        num_map[n] = i
    return False
