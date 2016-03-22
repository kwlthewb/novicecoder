import sys
import io

def getInt():
    result = int(input("Enter number: "))
    return result

def getInteger(prompt):
    result = int(input(prompt))
    return result

def Main():
    print("Started: ")
    output = getInteger("Enter ")
    print(output)

if __name__ == "__main__":
    Main()