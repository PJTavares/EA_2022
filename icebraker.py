from sys import stdin,stdout
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


def icebreaker(numeros):
    for i in range(len(numeros)-2):
        sec = i+1
        last = len(numeros)-1
        while(sec < last):
            if(numeros[i]+numeros[sec]+numeros[last] == 0):
                return 'Fair'
            elif(numeros[i]+numeros[sec]+numeros[last] > 0):
                last -= 1
            elif(numeros[i]+numeros[sec]+numeros[last] < 0):
                sec += 1
    return 'Rigged'



lido = 'n'
numeros = []
lido = readln()

while True:
    lido = readln()
    if(lido == ''):
        break
    
    elif(lido == '0'):
        #lidos.append(numeros)
        #numeros = []
        numeros.sort()
        outln(icebreaker(numeros))
        numeros = []
    
    else:
        numeros.append(int(lido))

