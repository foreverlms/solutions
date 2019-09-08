#!/usr/bin/env python3

'''
    leetcode 658
'''
arr = list(map(lambda x: int(x),input().split(',')))
k = int(input())
x = int(input())

size = len(arr)

i = 0
j=size-k
mid = 0
while i<j:
    mid = (j-i)//2+i
    if(abs(x-arr[mid]) > abs(arr[mid+k]-x)):
        i=mid+1
    else:
        j=mid

print("Here")
for it in range(i,i+k):
    print(arr[it]," ")