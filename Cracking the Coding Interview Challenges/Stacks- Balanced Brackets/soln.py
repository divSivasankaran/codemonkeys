#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        expression = input()

        stack = []
        match = {'(':')', '[':']', '{':'}'}
        for char in expression:
            # check if stack is empty
            if stack: # not empty
                # check if top (last element in list) is a match to current char
                if stack[-1] in match and match[stack[-1]] == char: # match yes
                    stack.pop(-1)
                else: # no match
                    stack.append(char)
            else: # empty
                stack.append(char)

        if stack:
            print("NO")
        else:
            print("YES")
