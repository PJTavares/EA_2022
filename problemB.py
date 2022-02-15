from sys import stdin,stdout

'''
Given an N = size of list in the first line
Followed by a line with all elements of the list
Output the list in reverse order
'''
def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")

size = int(readln())
elements = readln().split(' ')

l = list()
for elem in elements:
    l.append(int(elem))

l = l[::-1]
for i in range(size - 1):
    stdout.write(str(l[i])+' ')

outln(l[-1])
