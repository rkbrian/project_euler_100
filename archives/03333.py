#!/usr/bin/python3

def recur(arr, total, num):
    if len(arr) == 1 and total % arr[0] == 0: # if the total is divisible by the last coin
        return int(total / arr[0] + num)
    elif len(arr) == 1: # if the total is not divisible
        return -1
    """
    if len(arr) == 1 and total == arr[0]: # if the total equals to the last coin
        return num + 1
    elif len(arr) == 1: # if the total doesn't equal to the last coin
        return -1
    """
    if arr[0] > total: # case: coin denominations too big
        return recur(arr[1:], total, num)
    curr = recur(arr, total - arr[0], num + 1) # recursion to use the current coin
    next = recur(arr[1:], total, num) # recursion to use next coin
    if curr > 0 and next > 0: # choose the minimum / valid value
        return min(curr, next)
    elif curr > 0:
        return curr
    elif next > 0:
        return next
    return -1

def changeCoin(arr, total):
    if len(arr) == 0: # case: empty array
        return -1
    if total <= 0: # case: no coin used
        return 0
    if min(arr) > total: # case: coin denominations too big
        return -1
    return recur(arr, total, 0)

if __name__ == "__main__":
    print(changeCoin([5,1,2], 13))
    print(changeCoin([4,2,3], 13))
    print(changeCoin([4,2,3], 142857))
    # print(changeCoin([507, 500, 300, 200, 6, 5, 4, 3], 1413))
