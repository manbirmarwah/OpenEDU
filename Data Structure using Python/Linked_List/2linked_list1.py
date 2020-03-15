# Lets create a linked list that has the following elements 
'''
1. FE
2. SE
3. TE
4. BE
'''

# Creating a Node class to create individual Nodes

class Node:
    def __init__(self,data):
        self.__data = data
        self.__next = None
    
    def get_data(self):
        return self.__data
    
    def set_data(self, data):
        self.__data = data
    
    def get_next(self):
        return self.__next

    def set_next(self,next_node):
        self.__next = next_node

class LinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None

    def get_head(self):
        return self.__head

    def get_tail(self):
        return self.__tail

    
    # ADDING ELEMENT IN THE LINKED LIST
    def add(self,data):
        new_node = Node(data)

        if(self.__head==None):
            self.__head=self.__tail=new_node
        else:
            self.__tail.set_next(new_node)
            self.__tail=new_node
        



number_list= LinkedList()
number_list.add("FE")
number_list.add("SE")
number_list.add("TE")
number_list.add("BE")

