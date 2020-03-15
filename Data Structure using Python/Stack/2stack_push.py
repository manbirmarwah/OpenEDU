# Implement a stack

class Stack:
    def __init__(self,max_size):
        self.__max_size = max_size
        self.__element=[None]*self.__max_size
        self.__top =-1

    def get_max_size(self):
        return self.__max_size
    
    def is_full(self):
        if(self.__top ==self.__max_size-1):
            return True
        return False

    def is_empty(self):
        if(self.__top==-1):
            return True
        return False

    def push(self,data):
        if(self.is_full()):
            print("Stack is full")
        else:
            self.__top+=1
            self.__element[self.__top]=data
        

num_list = Stack(7)
num_list.push(1)
num_list.push(2)

