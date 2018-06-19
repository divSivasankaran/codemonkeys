import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(raw_input())

    a = map(int, raw_input().rstrip().split())
    bits=0
    for i in range(0,n):
        bits = bits^ 1<<a[i]        
        #print bits
    for i in range(0,n):
        mask=bits>>a[i] & 1
        #print mask
        if mask:
            print a[i]
        