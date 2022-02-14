from sys import stdin,stdout

def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")


n = int(readln())
outln(n)