#!/usr/bin/python3
"""
Techique used: dynamic programming, Python hates huge recursion
dp = table of solutions for each amount <= total
dp[i] = 1 for bigger coin replaces smaller coin result
if 1st solution is found, replace with count + 1
if another solution is here, replace with min(count + 1, local count)
"""


def changeCoin(arr, total):
    if len(arr) == 0:
        return -1
    if total <= 0:
        return 0
    if min(arr) > total:
        return -1
    dp = [-1] * (total + 1)
    for i in arr:
        if i < total + 1:
            dp[i] = 1
            for j in range(i + 1, total + 1):
                if dp[j - i] > 0 and dp[j] == -1:
                    dp[j] = dp[j - i] + 1
                elif dp[j - i] > 0:
                    dp[j] = min(dp[j - i] + 1, dp[j])
    return dp[total]

if __name__ == "__main__":
    print(changeCoin([5,1,2], 13))
    print(changeCoin([4,2,3], 13))
    print(changeCoin([4,2,3], 142857))
