#!/bin/python3

import math
import os
import random
import re
import sys

map_a = dict()
map_b = dict()

if __name__ == '__main__':
    a = input()
    b = input()
    count = 0
    for t in a:
        if t in b:
            b_l = list(b)
            del(b_l[b.index(t)])
            b = ("").join(b_l)
        else:
            count += 1
    count += len(b)
    print(count)
    
