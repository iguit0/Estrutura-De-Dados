# Fila com 2 pilhas.
# A fila deve enfileirar e desenfileirar e deve ser FIFO (first in first out)

class Stack(object):

    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def isEmpty(self):
        return not self.items

    def length(self):
        return len(self.items)

    def at(self, index):
        return self.items[index]

class Queue(object):

    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()

    def enqueue(self, item):
        self.stack1.push(item)

    def dequeue(self):
        self.swapStack()
        return self.stack2.pop()

    def swapStack(self):
        # Se a pilha 2 esta vazia, copie todos elementos da pilha 1
        if self.stack2.isEmpty():
            while not self.stack1.isEmpty():
                self.stack2.push(self.stack1.pop())

    def __str__(self):
        output = []
        for i in range(self.stack2.length()-1, -1, -1):
            output.append(self.stack2.at(i))
        for i in range(0, self.stack1.length()):
            output.append(self.stack1.at(i))
        return str(output)

if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(4)
    queue.enqueue(5)
    print(queue)
    queue.dequeue()
    print(queue)
    queue.dequeue()
    queue.dequeue()
    print(queue)
    queue.enqueue(6)
    queue.enqueue(7)
    print(queue)
    queue.dequeue()
    queue.dequeue()
    print(queue)
