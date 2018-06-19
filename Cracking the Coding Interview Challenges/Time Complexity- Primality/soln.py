#!/bin/python

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    p = int(raw_input())

    for p_itr in xrange(p):
        flag=True
        n = int(raw_input())
        if n==1:
            print 'Not prime'
            continue
        if n==2:
            print 'Prime'
            continue
        root=math.sqrt(n)
        if n%2 == 0:
            flag=False
        i=3
        while flag and i <= root:
            if n%i == 0:
                flag=False
            i+=2
        if flag:
            print 'Prime'
        else:
            print 'Not prime'
#!/bin/python

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    p = int(raw_input())

    for p_itr in xrange(p):
        flag=True
        n = int(raw_input())
        if n==1:
            print 'Not prime'
            continue
        if n==2:
            print 'Prime'
            continue
        root=math.sqrt(n)
        if n%2 == 0:
            flag=False
        i=3
        while flag and i <= root:
            if n%i == 0:
                flag=False
            i+=2
        if flag:
            print 'Prime'
        else:
            print 'Not prime'
