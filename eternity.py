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


def eternity(tabuleiro,pecas,rows,collumns):
    print("=== Todas as pecas ",pecas," ===")
    print("=== Possiveis combinacoes da peca: ",pecas[0]," ===")
    print("Resultado: ",rotate(pecas[0]))
    print("Resultado: ",rotate(pecas[0]))
    print("Resultado: ",rotate(pecas[0]))
    return

def insereDireita(peca1,peca2):
    if(peca1[1] == peca2[0] and peca1[2] == peca2[3]):
        return True
    return False


def insereEsquerda(peca1,peca2):
    if(peca1[0] == peca2[1] and peca1[3] == peca2[2]):
        return True
    return False
    
def insereCima(peca1,peca2):
    if(peca1[0] == peca2[3] and peca1[1] == peca2[2]):
        return True
    return False
    
def insereBaixo(peca1,peca2):
    if(peca1[2] == peca2[1] and peca1[3] == peca2[0]):
        return True
    return False


def rotate(peca):
    peca[0],peca[1],peca[2],peca[3] = peca[3],peca[0],peca[1],peca[2]
    return peca


def run():
    num_cases = readln()
    #para cada caso de teste
    for i in range(int(num_cases)):
        pecas = []
        n,r,c = readln().split(' ')
        print("=== Caso %d ==="%(i))
        print("=== Numero Pecas %d Rows %d Collumns %d ==="%(int(n),int(r),int(c)))
        #Ler cada peca
        for j in range(int(n)):
            peca = []
            lidos = readln().split(' ')

            for k in range(len(lidos)):
                peca.append(int(lidos[k]))

            #pecas = lista de todas as pecas
            pecas.append(peca)
        
        #cria um tabuleiro de dimensoes r*c
        tabuleiro = []
        for i in range(int(r)):
            aux = []
            for j in range(int(c)):
                aux.append([])
            tabuleiro.append(aux)

        #peca fixa
        tabuleiro[0][0] = pecas[0]
        #chamar a funcao para cada caso
        eternity(tabuleiro,pecas,r,c)

#run()
print(insereEsquerda([1,2,3,4],[5,1,4,6]))
print(insereDireita([1,2,3,4],[2,5,6,3]))
print(insereCima([1,2,3,4],[6,5,2,1]))
print(insereBaixo([1,2,3,4],[4,3,5,6]))