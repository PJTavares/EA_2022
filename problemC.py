from sys import stdin,stdout

'''
Given an array which the elements are all in separete lines
Read until EOF to get array and output the sorted array
'''
def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")

l = list()
lido = 'n'
while True:
    lido = readln()
    if(lido == ''):
        break

    l.append(int(lido))
    
l.sort()
for elem in l:
    outln(elem)


