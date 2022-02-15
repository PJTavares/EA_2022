from sys import stdin,stdout

def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")

string = readln()
first, second = string.split(' ')
outln(int(first)*int(second))
