#!/bin/python3

import math
import os
import random
import re
import sys

def isPrime(n):
    if n <= 1:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False

    return True

if __name__ == '__main__':
    p = int(input())

    for p_itr in range(p):
        n = int(input())
        if isPrime(n):
            print("Prime")
        else:
            print("Not prime")
