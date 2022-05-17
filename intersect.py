from sys import stdin,stdout
'''
run on linux shell
python3 -m py_compile intersect.py
python3 intersect.py < input.txt
YVU70v password mooshak
'''

def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")


number_cubes = int(readln())
cubos = []
for i in range(number_cubes):
    aux = []
    data = readln()
    coordenadas = data.split(' ')
    for coor in coordenadas:
        aux.append(int(coor))
    cubos.append(aux)
