from sys import stdin,stdout

#compile using python3 -m py_compile $file$
#run using python3 $file$
#--- mooshak ---
#2018280907
#ffBpCs

def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")

def list_EOF():
    l = list()
    while True:
        try:
            n = readln()
            l.append(n)
        except Exception:
            break    
    return l
'''
Ler ate ao fim
while True:
    try:
        n = int(readln())
        outln(n)
    except Exception:
        break
'''