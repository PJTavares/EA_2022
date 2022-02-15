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
        ins.prev = self.prev
        self.prev = ins
        ins.next = self
        print(ins.value)

    def insert_after(self,value):
        ins = Node(value)
        ins.next = self.next
        self.next = ins
        ins.prev = self
        print(ins.value)

class LinkedList:
    def __init__(self):
        self.head = Node(0)
        self.tail = None

    def insert_back(self,value):
        self.head.insert_before(value)
        print("HEAD VALUE: "+str(self.head.value))
        print("Before VALUE: "+str(self.head.prev.value))

    def insert_front(self,value):
        self.head.insert_after(value)
        
        print("HEAD VALUE: "+str(self.head.value))
        print("AFTER VALUE: "+str(self.head.next.value))

    def pop_back(self):
        pass
    def pop_front(self):
        pass

lista = LinkedList()
lista.insert_back(5)
lista.insert_front(10)

aux = lista.head
while aux:
    print(aux.value)
    aux = aux.next


'''
l = list()
while True:
    lido = readln()
    if(lido == ''):
        break

    print(lido)

    
for elem in l:
    outln(elem)
'''

