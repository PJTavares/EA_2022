from sys import stdin,stdout
import sys
import math
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



def tree(v,cost):
    global solved

    if v == int(net_nodes) and cost < solved:
        solved = cost
        return
    
    for i in range(int(net_nodes)):
        if visited[i] == 0:
            for j in range(int(net_nodes)):
                if visited[j] == 0: #supostamente devia estar a 1
                    if custo[i][j] > 0 and grau[j] < int(max_feasibile):
                        grau[i] += 1
                        grau[j] += 1
                        visited[i] = 1
                        tree(v+1,cost+custo[i][j])
                        visited[i] = 0
                        grau[i] -= 1
                        grau[j] -= 1


lido = 'n'
while True:
    global custo
    global visited
    global grau
    global solved
    global net_nodes
    global feasibile
    global max_feasibile

    lido = readln()
    if(lido == ''):
        break
    
    net_nodes,feasibile,max_feasibile = lido.split(' ')
    solved = math.inf
   
    custo = []
    visited = []
    grau = []
    
    for i in range(int(net_nodes)):
        aux = []
        visited.append(0)
        grau.append(0)
        for j in range(int(net_nodes)):
            aux.append(0)
        custo.append(aux)
    
    for i in range(int(feasibile)):
        i,j,cust_node = readln().split(' ')
        i = int(i)
        j = int(j)
        cust_node = int(cust_node)
        
        custo[i-1][j-1] = cust_node

    tree(1,0)
    if(solved < math.inf):
        outln(solved)
    else:
        outln("NO WAY!")