def triangle(row):
        if row is None or len(row) == 0:
                return ""
        elif len(row) == 1:
                return row[0]
        stry = "RGB"
        dicty = {'R':0, 'G':1, 'B':2}
        temp = []
        rowCopy = []
        for i in range(len(row)):
                rowCopy.append(dicty[row[i]])
        while len(rowCopy) > 1:
                for i in range(len(rowCopy) - 1):
                        temp.append((6 - rowCopy[i] - rowCopy[i + 1]) % 3)
                rowCopy = temp
                temp = []
        return stry[rowCopy[0]]

def superTriangle(row):
        if row is None or len(row) == 0:
                return ""
        elif len(row) == 1:
                return row[0]
        stry = "RGB"
        dicty = {'R':0, 'G':1, 'B':2}
        goal = 0
        k = 1
        size = int(len(row))
        if size % 2 == 0:
                for i in range(int(size / 2)):
                        goal -= k * (dicty[row[i]] + dicty[row[size - 1 - i]])
                        k = k * (size - 1 - i) // (i + 1)
        else:
                for i in range(int(size / 2) + 1):
                        goal += k * dicty[row[i]]
                        if i < int(size / 2):
                                goal += k * dicty[row[size - 1 - i]]
                        k = k * (size - 1 - i) // (i + 1)
        return stry[int(goal) % 3]

if __name__ == "__main__":
        basic_cases = [
    ['B', 'B'],
    ['GB', 'R'],
    ['RRR', 'R'],
    ['RGBG', 'B'],
    ['RBRGBRB', 'G'],
    ['RBRGBRBGGRRRBGBBBGG', 'G']
]
        longStr = 'RBRGBRBGGRRRBGBBBGG' * 5000
        longStrt = 'G' * 50000
        for i in basic_cases:
                print("Regular logic:      " + triangle(i[0]))
                print("Pascal coefficient: " + superTriangle(i[0]))
                print("Real value:         " + i[1])
        print('================')
        print("Super long: " + superTriangle(longStr))
        print("Super long: " + superTriangle(longStrt))
