#!/bin/python

import math
import os
import random
import re
import sys

# Complete the ways function below.
def ways(n, m, coins):
    alist=[0]*(n+1)
    alist[0]=1
    for i in range(0,m):
        for j in range(coins[i],n+1):
            alist[j]+=alist[j-coins[i]]
    return alist[n]
    
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = raw_input().split()

    n = int(nm[0])

    m = int(nm[1])

    coins = map(int, raw_input().rstrip().split())
    coins.sort()

    res = ways(n, m, coins)

    fptr.write(str(res) + '\n')

    fptr.close()
#!/bin/python

import math
import os
import random
import re
import sys

# Complete the ways function below.
def ways(n, m, coins):
    alist=[0]*(n+1)
    alist[0]=1
    for i in range(0,m):
        for j in range(coins[i],n+1):
            alist[j]+=alist[j-coins[i]]
    return alist[n]
    
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = raw_input().split()

    n = int(nm[0])

    m = int(nm[1])

    coins = map(int, raw_input().rstrip().split())
    coins.sort()

    res = ways(n, m, coins)

    fptr.write(str(res) + '\n')

    fptr.close()
