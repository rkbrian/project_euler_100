#!/usr/bin/python3
"""
Techique used: dynamic programming, Python hates huge recursion
dp = table of solutions for each amount <= total
dp[i] = 1 for bigger coin replaces smaller coin result
if 1st solution is found, replace with count + 1
if another solution is here, replace with min(count + 1, local count)
"""


def changeCoin(arr, total):
    if len(arr) == 0: # case: empty array
        return -1
    if total <= 0: # case: no coin used
        return 0
    if min(arr) > total: # case: coin denominations too big
        return -1
    arr = sorted(arr, reverse=True)
    num = 0
    for i in arr:
        if total >= i:
            num += int(total / i)
            total = total % i
    if total == 0:
        return num
    return -1

if __name__ == "__main__":
    print(changeCoin([5,1,2], 13))
    print(changeCoin([4,2,3], 13))
