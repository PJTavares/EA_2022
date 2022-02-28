from sys import stdin,stdout

'''
You start with a list that contains a single value 0, and a pointer to that value. 
Then you receive a list of instructions that can take the following values:

  MOVE LEFT
  MOVE RIGHT
  INSERT LEFT int
  INSERT RIGHT int
The first two instruct you to move the pointer to the left or to the right respectively. 
It is guaranteed that you will never move beyond the limits of the list. 
The last two instructions tells you to insert a new integer before or after the current pointer.
Note that, when you insert an element, the pointer does not move.
When there are no more instructions you should print the list, one value per line.
'''
def readln():
    return stdin.readline().rstrip()

def outln(n):
    stdout.write(str(n))
    stdout.write("\n")


class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
        self.prev = None

    def insert_before(self,value):
        ins = Node(value)
        if(self.prev == None):
            self.prev = ins
            ins.next = self
            return

        self.prev.next = ins
        ins.prev = self.prev
        self.prev = ins
        ins.next = self

    def insert_after(self,value):
        ins = Node(value)
        if(self.next == None):
            self.next = ins
            ins.prev = self
            return

        self.next.prev = ins    
        ins.next = self.next
        self.next = ins
        ins.prev = self
      

class LinkedList:
    def __init__(self):
        self.head = Node(0)
        self.tail = None

    def insert_back(self,value):
        self.head.insert_before(value)
        
    def insert_front(self,value):
        self.head.insert_after(value)
        
    def printlist(self):
        aux = self.head
        while(aux.prev):
            aux = aux.prev
        
        while aux:
            outln(aux.value)
            aux = aux.next


lista = LinkedList()

while True:
    lido = readln()
    if(lido == ''):
        break

    comandos = lido.split(' ')

    if(comandos[0] == 'INSERT'):
        if(comandos[1] == 'RIGHT'):
            lista.insert_front(int(comandos[2]))
        elif(comandos[1] == 'LEFT'):
            lista.insert_back(int(comandos[2]))

    elif (comandos[0] == 'MOVE'):
        if(comandos[1] == 'RIGHT'):
            lista.head = lista.head.next
        elif(comandos[1] == 'LEFT'):
            lista.head = lista.head.prev
            

lista.printlist()