# A simple program to create list and do list operations 

# Lets create a list

num = []

# Let us take an integer as a  user input in a list
x = int(input("Enter an element: "))
num.append(x)
print(num)

# Taking multiple inputs

for x in range(1,5):
    num.append(int(input("Enter element : ")))
print(num)

# Delete the last element
num.pop() 
print(num)

# Deleting a specific element
data = input("Enter the number to be deleted: ")
num.remove(data)
print(num)

# Deleting a complete list
num.clear()
print(num)
