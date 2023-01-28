"""
-- Prologue --
My mother is a Sudoku zealot, she buys tons of Sudoku puzzle books to play.
I made this program that can generate Sudoku puzzles, which I plan to give to her
as a birthday gift. (And this should save her money from buying more books! 😡)
I didn't invent the wheel, it is a hack project based on the following link:
    Sudoku Generator Algorithm - www.101computing.net/sudoku-generator-algorithm/

-- Develop Progress --
The original code was very basic, it generates a random Sudoku puzzle, but I wanted more!
I wanted to add controls with inputs for the following parameters:
    1. Diffculty (Easy / Medium / Hard / Expert) ---- done
    2. Layout preference (No preference / Symmetrical / Axial) ---- done
    3. Expert level: one certain number is not hinted (e.g. all given numbers in the grid
        does not include "7") ---- done

-- Features --
1. Selectable difficulty (4 choices)
2. Selectable preference of the given number layout
    (no preference / random, symmetrical layout, axial layout)
3. Expert level difficulty: the clue numbers are not all 9 types, it is missing one type
4. Generating a solution / answer grid is optional, before generating the puzzle
    (answer would be shown for 10 seconds, then turn into puzzle grid)
5. Python-Turtle window drawing the grid and the numbers

-- Outcome --
Total hours of developing: 10
I'm very satisfied! Score 10/10 to myself!
Issues: needs an automatic method to save the puzzle or the answer grid images, right now
    the user has to take screenshots. Pylance hates Image or Imagegrab imports
"""
import turtle
import datetime
from random import randint, shuffle
from enum import Enum
from time import sleep

class Difficulty(Enum):
    EASY = 1
    MEDIUM = 2
    HARD = 3
    EXPERT = 4

class Preference(Enum):
    NO_PREF = 1
    SYMMETRICAL = 2
    AXIAL = 3

def inputValidator(myInput):
    try:
        return int(myInput)
    except ValueError:
        print('Please enter a valid integer.')

penColorBlack = "#000000"
penColorLight = "#FFFFFF"
attempts = 5
exitCode = 1
sleepSeconds = 0
"""Input console"""
while (exitCode):
    diffNum = input('Select diffculty: 1-Easy, 2-Medium, 3-Hard, 4-Expert\n')
    if (inputValidator(diffNum) in (item.value for item in Difficulty)):
        while (exitCode):
            preferenceNum = input('Select layout preference: 1-no preference, 2-symmetrical, 3-axial\n')
            if (inputValidator(preferenceNum) in (item.value for item in Preference)):
                while (exitCode):
                    answerBool = input('Do you want to have an answer grid? (Y/N)\n')
                    if (answerBool.lower() == 'y' or answerBool.lower() == 'yes'):
                        sleepSeconds = 10
                        attempts = 2 + int(diffNum) * 3
                        exitCode = 0
                        print('You have {} seconds to take the screenshot.'.format(sleepSeconds))
                    elif (answerBool.lower() == 'n' or answerBool.lower() == 'no'):
                        attempts = 2 + int(diffNum) * 3
                        exitCode = 0
                    else:
                        print('Please answer yes or no.')

"""initialise empty 9 by 9 grid"""
grid = [[0] * 9 for i in range(9)]
myPen = turtle.Turtle()
myPen._tracer(0)
myPen.speed(0)
myPen.hideturtle()
topLeft_x = -150
topLeft_y = 150

def text(message, x, y, size, visibility = True):
    FONT = ('Arial', size, 'normal')
    myPen.penup()
    myPen.goto(x, y)
    if (visibility):
        myPen.color(penColorBlack)
    else:
        myPen.color(penColorLight)
    myPen.write(message, align="left", font = FONT)

"""A procedure to draw the grid on screen using Python Turtle"""
def drawGrid(grid, visibility = True):
    intDim = 35
    myPen.color(penColorBlack)
    for row in range(0, 10):
        if (row % 3) == 0:
            myPen.pensize(3)
        else:
            myPen.pensize(1)
        myPen.penup()
        myPen.goto(topLeft_x, topLeft_y - row * intDim)
        myPen.pendown()
        myPen.goto(topLeft_x + 9 * intDim,topLeft_y - row * intDim)
    for col in range(0, 10):
        if (col % 3) == 0:
            myPen.pensize(3)
        else:
            myPen.pensize(1)
        myPen.penup()
        myPen.goto(topLeft_x + col * intDim, topLeft_y)
        myPen.pendown()
        myPen.goto(topLeft_x + col * intDim, topLeft_y - 9 * intDim)
    for row in range (0, 9):
        for col in range (0, 9):
            if grid[row][col] != 0:
                text(grid[row][col], topLeft_x + col * intDim + 13, topLeft_y - row * intDim - intDim + 3, 18, visibility)

"""A function to check if the grid is full"""
def checkGrid(grid):
    for row in range(0, 9):
        for col in range(0, 9):
            if grid[row][col] == 0:
                return False
    return True 

"""A backtracking/recursive function to check all possible combinations of numbers until a solution is found"""
def solveGrid(grid):
    global counter
    # Find next empty cell
    for i in range(0, 81):
        row = i // 9
        col = i % 9
        if grid[row][col] == 0:
            for value in range (1, 10):
                # Check that this value has not already be used on this row and this column
                cols = (grid[x][col] for x in range(9))
                if not(value in grid[row]) and not(value in cols):
                    # Identify which of the 9 squares we are working on
                    a = row // 3
                    b = col // 3
                    square = [grid[i][b * 3 : (b + 1) * 3] for i in range(a * 3, (a + 1) * 3)]
                    # Check that this value has not already be used on this 3x3 square
                    if not value in (square[0] + square[1] + square[2]):
                        grid[row][col] = value
                        if checkGrid(grid):
                            counter += 1
                            break
                        else:
                            if solveGrid(grid):
                                return True
            break
    grid[row][col] = 0

numberList = [1, 2, 3, 4, 5, 6, 7, 8, 9]

"""A backtracking/recursive function to check all possible combinations of numbers until a solution is found"""
def fillGrid(grid):
    global counter
    # Find next empty cell
    for i in range(0, 81):
        row = i // 9
        col = i % 9
        if grid[row][col] == 0:
            shuffle(numberList)
            for value in numberList:
                # Check that this value has not already be used on this row and this column
                cols = (grid[x][col] for x in range(9))
                if not(value in grid[row]) and not(value in cols):
                        # Identify which of the 9 squares we are working on
                        a = row // 3
                        b = col // 3
                        square = [grid[i][b * 3 : (b + 1) * 3] for i in range(a * 3, (a + 1) * 3)]
                        # Check that this value has not already be used on this 3x3 square
                        if not value in (square[0] + square[1] + square[2]):
                            grid[row][col] = value
                            if checkGrid(grid):
                                return True
                            else:
                                if fillGrid(grid):
                                    return True
            break
    grid[row][col] = 0

"""Generate a Fully Solved Grid."""
fillGrid(grid)
drawGrid(grid)
myPen.getscreen().update()
if (sleepSeconds):
    sleep(sleepSeconds)
print('Generating your puzzle...')

"""
Start Removing Numbers one by one
A higher number of attempts will end up removing more numbers from the grid
Potentially resulting in more difficiult grids to solve!
"""
counter = 1
prefNum = int(preferenceNum)
# Difficulty: EXPERT has 8 types of numbers at most
if (int(diffNum) == Difficulty.EXPERT.value):
    extinctionNum = randint(1, 9)
    for i in range(9):
        for j in range(9):
            if (grid[i][j] == extinctionNum):
                if (prefNum == Preference.SYMMETRICAL.value and j != 4):
                    grid[i][8 - j] = 0
                elif (prefNum == Preference.AXIAL.value and not(i == 4 and j == 4)):
                    grid[8 - i][8 - j] = 0
                grid[i][j] = 0
while attempts > 0:
    # Select a random cell that is not already empty
    row = randint(0, 8)
    col = randint(0, 8)
    while grid[row][col] == 0:
        row = randint(0, 8)
        col = randint(0, 8)
    # Remember its cell value in case we need to put it back
    backup = grid[row][col]
    grid[row][col] = 0
    twinrow = row
    if (prefNum == Preference.AXIAL.value and not(row == 4 and col == 4)):
        twinrow = 8 - row
    twincol = 8 - col
    twinbackup = grid[twinrow][twincol]
    if (prefNum == Preference.SYMMETRICAL.value and col != 4):
        grid[twinrow][twincol] = 0
    elif (prefNum == Preference.AXIAL.value and not(row == 4 and col == 4)):
        grid[twinrow][twincol] = 0
    # Take a full copy of the grid
    copyGrid = []
    for r in range(0, 9):
        copyGrid.append([])
        for c in range(0, 9):
            copyGrid[r].append(grid[r][c])
    # Count the number of solutions that this grid has (using a backtracking approach implemented in the solveGrid() function)
    counter = 0
    solveGrid(copyGrid)   
    # If the number of solution is different from 1 then we need to cancel the change by putting the value we took away back in the grid
    if counter != 1:
        grid[row][col] = backup
        if (prefNum == Preference.SYMMETRICAL.value and col != 4):
            grid[twinrow][twincol] = twinbackup
        elif (prefNum == Preference.AXIAL.value and not(row == 4 and col == 4)):
            grid[twinrow][twincol] = twinbackup
        # We could stop here, but we can also have another attempt with a different cell just to try to remove more numbers
        attempts -= 1
    myPen.clear()
    drawGrid(grid, False)
    myPen.getscreen().update()
myPen.clear()
drawGrid(grid)
myPen.getscreen().update()
codeMessage = 'Difficulty: ' + Difficulty(int(diffNum)).name.lower() + '\nCreated by: Brian Kong\n' + str(datetime.date.today())
text(codeMessage, topLeft_x + 0 * 35 + 9, topLeft_y - 10 * 35 - 35 + 8, 10)
print('Sudoku is successfully generated!')
turtle.mainloop()
