from sys import stdin,stdout
'''
run on linux shell
python3 -m py_compile icebraker.py
python3 icebraker.py < input.txt
YVU70v password mooshak
'''
board =[[0 for i in range(400)] for j in range(400)]
    
def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")

def chess(x,y,moves):
    global board
    v = 0

    if(moves < 0 or x < 0 or x == 400 or y < 0 or y == 400):
        return 0
    
    if(board[x][y] == 0):
        board[x][y] = 1
        v = 1

    return v + (
    chess(x-2,y+1,moves-1)+
    chess(x-2,y-1,moves-1)+
    chess(x-1,y+2,moves-1)+
    chess(x-1,y-2,moves-1)+
    chess(x+1,y+2,moves-1)+
    chess(x+1,y-2,moves-1)+
    chess(x+2,y+1,moves-1)+
    chess(x+2,y-1,moves-1))

num_knights = int(readln())
total_moves = 0
for i in range(num_knights):
    x,y,moves = readln().split(' ')
    total_moves += chess(int(x)+200,int(y)+200,int(moves))

outln(total_moves)