# # Uses python3
import sys

n = int(input())
srt = [int(i) for i in input().split()]
count = 0

def MergeSort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    L = MergeSort(arr[:mid])
    R = MergeSort(arr[mid:])
    O = Merge(L, R)
    return O

def Merge(L, R):
    i = 0
    j = 0
    out = []
    global count
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            out.append(L[i])
            i += 1
        else:
            out.append(R[j])
            count += len(L) - i
            j += 1
    if i == len(L):
        while j < len(R):
            out.append(R[j])
            j += 1
    else:
        while i < len(L):
            out.append(L[i])
            i += 1
    return out

MergeSort(srt)
print(count)
