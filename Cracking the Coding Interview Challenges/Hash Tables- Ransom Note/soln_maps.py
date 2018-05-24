#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    ransom = input().rstrip().split()

    # Construct a dictionary of the words in the magazine,
    # along with their counts of occurrence
    magcol = {}
    for word in magazine:
        if word in magcol:
            magcol[word] += 1
        else:
            magcol[word] = 1

    # For each word in ransom, "cut out" words from the magazine dictionary
    # by reducing the count for the word
    for word in ransom:
        if word in magcol:
            magcol[word] -= 1
        else:
            magcol[word] = -1

    # Check if any of the occurrence count is less than zero, indicating
    # that words other than those present in the dictionary are required
    status = True
    for key in magcol:
        if magcol[key] < 0 :
            status = False

    if status:
        print("Yes")
    else:
        print("No")
