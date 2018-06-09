#!/bin/python

import math
import os
import random
import re
import sys

arr=[]
temparr=[]
# Complete the countInversions function below. 
#Do a merge sort i) count every swap at the leaves. ii) while merging, everytime a element from second array is put, count the number of elements remaining in the first array
count=0
def countInversions(start,last):
    
    global count
    if start==last:
        return
    if last==start+1:
        if arr[start]>arr[last]:
            arr[start],arr[last] = arr[last],arr[start]
            count+=1
        return count
    mid=(start+last)/2
    countInversions(start,mid)
    countInversions(mid+1,last)
    p1=start
    p2=mid+1
    
    ind=0
    while ind<last-start+1 :

        if p1==mid+1:
            temparr[ind]=arr[p2]
            p2+=1
            ind+=1
            continue
        if p2==last+1:
            temparr[ind]=arr[p1]            
            p1+=1
            ind+=1
            continue
        
        if arr[p1]<=arr[p2]:
            temparr[ind]=arr[p1]
            p1+=1
            ind+=1
            continue
        else:	    
            temparr[ind]=arr[p2]
            p2+=1
            count+=mid-p1+1
            ind+=1
    arr[start:last+1]=temparr[0:ind]
    return count         
            

if __name__ == '__main__':

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        arr=[]
        arr = map(int, raw_input().rstrip().split())
        temparr=[0]*n
        count=0

        result = countInversions(0,len(arr)-1)

        print result

    
