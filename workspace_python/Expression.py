import sys
import io

def hello():
    print("Hello")

num = int(input("Enter number: "))

if num == 0:
    print("Number is zero", num)
elif num < 0:
    print("Number is negative", num)
else:
    print("Number is normal", num)

hello()