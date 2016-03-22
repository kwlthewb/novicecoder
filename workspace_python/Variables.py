import sys
import io

myNum = 3
print(myNum)

myNum = 10
print(myNum)

text = "hello world"
print(text)

nums = []
nums.append(99)
nums.append("test")
nums.append(1.23)
print(nums[0])
print(nums[1])
print(nums[2])

nums = [1,2,-56.7,5,6,"blah","blah",45.99,"crap"]

print(nums)

nums = {'ftp': 21, 'ssh': 22, 'smtp': 25, 'http': 80}

print(nums)

name = "draps"
print(name + "Hello, my name is ")
print("Hello, my name is", name)

name = input("Enter name: ")
print("Hello, my name is", name)

n1 = int(input("Enter number: "))
print("Number is " + str(n1))
print("Number is",n1)

exit()