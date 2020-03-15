# Lets initialise a Queue

class Queue:
    def __init__(self,max_size):
        self.__max_size = max_size
        self.__front = 0
        self.__rear = -1
        self.__element = [None]*self.__max_size


    def get_max_size(self):
        return self.__max_size
    
    def is_empty(self):
        if (self.__front>self.__rear):
            return True
        return False
    
    def is_full(self):
        if (self.__rear==self.__max_size-1):
            return True
        return False
    
    def enqueue(self,data):
        if (self.is_full()):
            print("Queue is full")
        else:
            self.__rear+=1
            self.__element[self.__rear]=data
    
    def dequeue(self):
        if (self.is_empty()):
            print("Queue is Empty")
        else:
            data = self.__element[self.__front]
            self.__front+=1
            return data 

    def display(self):
        for index in range(self.__front,self.__rear+1):
            print(self.__element[index])
    

num_queue = Queue(7)
num_queue.enqueue(2)
num_queue.enqueue(7)
num_queue.enqueue(9)
num_queue.enqueue(4)
num_queue.enqueue(6)
num_queue.enqueue(5)
num_queue.enqueue(10)
num_queue.display()
data = num_queue.dequeue()
# print(data)
num_queue.display()


