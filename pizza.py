from sys import stdin,stdout
import sys
sys.setrecursionlimit(2500)

'''
run on linux shell
python3 -m py_compile icebraker.py
python3 icebraker.py < input.txt
YVU70v password mooshak
'''

def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")


def pizza(times,media,num_pizzas):
    DP = []
    for i in range(num_pizzas+1):
        aux = []
        for j in range(media+1):
           aux.append(False)
        
        DP.append(aux)

    for i in range(num_pizzas+1):
        DP[i][0] = True
    for j in range(media):
        DP[0][j+1] = False

    for i in range(num_pizzas):
        for j in range(media+1):
            if times[i] > j:
                DP[i+1][j] = DP[i][j]
            else:
                DP[i+1][j] = DP[i][j] or DP[i][j-times[i]]

        
    '''
    for i in range(num_pizzas+1):
        out = ""
        for j in range(media+1):
            out += str(DP[i][j]) + " "
        print(out)
    '''
    return

while True:
    num_pizzas = readln()
    if(num_pizzas == ''):
        break
    print("NOVO CASO TESTE\n")

    times = []
    sum = 0
    for i in range(int(num_pizzas)):
        lido = int(readln())
        times.append(lido)
        sum += lido

    pizza(times,sum//2,int(num_pizzas))