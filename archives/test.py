#!/usr/bin/python3

def closestPrime(n):
    if n <= 2:
        return 2
    elif n % 2 == 0:
        n += 1
    while True:
        flag = 0
        for factor in range(3, int(n ** 0.5) + 1, 2):
            if n % factor == 0 and n != factor:
                flag += 1
                break
        if flag == 0:
            return n
        n += 2  # skip even numbers

if __name__ == "__main__":
    for i in range(1, 20):
        print(i, closestPrime(i))
    print(3 % 3)
