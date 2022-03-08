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

lido = 'n'
while True:
    lido = readln()
    if(lido == ''):
        break

    net_nodes,feasibile,max_feasibile = lido.split(' ')
    custo = []
    visited = []
    grau = []
    print("=== NOVO CASO ===")
    for i in range(int(net_nodes)):
        aux = []
        visited.append(0)
        custo.append(0)
        for j in range(int(net_nodes)):
            aux.append(0)
        grau.append(aux)
    
    for i in range(int(feasibile)):
        #i,j,cust_node = lido.split(' ')
        print(readln())
