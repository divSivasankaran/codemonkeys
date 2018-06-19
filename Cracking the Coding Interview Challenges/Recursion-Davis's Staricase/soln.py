#!/bin/python

import math
import os
import random
import re
import sys

# Complete the stepPerms function below.

def stepPerms(n,steps):
    if steps[n] != -1:
        return steps[n]
    if steps[n-1]==-1:
        steps[n-1]=stepPerms(n-1,steps)
    if steps[n-2]==-1:
        steps[n-2]=stepPerms(n-2,steps)
    if steps[n-3]==-1:
        steps[n-3]=stepPerms(n-3,steps)
    steps[n]=steps[n-1]+steps[n-2]+steps[n-3]
    return steps[n]
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = int(raw_input())

    for s_itr in xrange(s):
        n = int(raw_input())
        if n==0:
            res = 0
        elif n==1:
            res = 1
        elif n==2:
            res = 2
        elif n==3:
            res = 4
        else:
            steps=[-1]*(n+1)
            steps[0]=0
            steps[1]=1
            steps[2]=2
            steps[3]=4
            res = stepPerms(n,steps)

        fptr.write(str(res) + '\n')

    fptr.close()