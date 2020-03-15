# Lets initialise a Queue

class Queue:
    def __init__(self,max_size):
        self.__max_size = max_size
        self.__front = 0
        self.__rear = -1
        self.__element = [None]*self.__max_size


    