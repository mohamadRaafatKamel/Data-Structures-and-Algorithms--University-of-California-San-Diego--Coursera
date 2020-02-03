# Author : Mohamad Raafat Mohamad
# some hhelp from : https://www.dazhuanlan.com/2019/10/12/5da1ec3abd92d/
# Uses python3
import sys

def fibonacci_sum_more_fast(n):
    if n <= 1:
        return n
    A = [None]* (100)
    A[0] = 0
    A[1] = 1
    for i in range(2, 100):
        A[i] = (A[i-1] + A[i-2]) % 10
        if A[i] == 1 and A[i-1] == 9:
            period = i+1
            break
    t = n % period
    if t == 0:
        t = period-1
    return (2*A[t] + A[t-1] - 1) % 10

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum_more_fast(n))
