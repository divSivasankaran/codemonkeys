def swap(a, c, r, nr):
    # Uncomment this to understand/debug

    # print("move %d, %d to %d, %d" %(r,c,c,nr))
    # print(" same iter %d, %d to %d, %d" %(c,nr,nr,nr-c + r))
    # print(" same iter %d, %d to %d, %d" %(nr,nr-c + r, nr-c + r, r))
    # print(" same iter %d, %d to %d, %d" %(nr-c + r, r,r,c)

    temp = a[r][c]  # this is the only additional space we take => O(1) space
    a[r][c] = a[nr-c + r][r] # since we do inplace swaps we don't need to store anything else
    a[nr-c + r][r] = a[nr][nr-c + r]
    a[nr][nr-c + r] = a[c][nr]
    a[c][nr] = temp
    return a
def rotateImage(a):
    n = len(a[0]);
    r=0
    nr = n-1
    while(r<nr):
        # for every pair of rows (consider first and last, and keep moving inwards)
        for c in range(r,nr):
            # iterate through the columns & swap the rows & columns
            a = swap(a,c,r,nr)
        r += 1
        nr-= 1
    return a
