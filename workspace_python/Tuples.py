import random
import sys
import os

pi_tuple = (3,1,4,1,5,9)
print('pi_tuple: ', pi_tuple, ' len: ', len(pi_tuple), ' min: ', min(pi_tuple), ' max: ', max(pi_tuple))
new_tuple = list(pi_tuple)
print('new_tuple: ', new_tuple, ' len: ', len(new_tuple), ' min: ', min(new_tuple), ' max: ', max(new_tuple))

super_villains = {'Fiddler' : 'Isacc Bowin', 'Captain Cold': 400, 'Weather Wizard': 'Mark Mardon',
                  'Mirror Master': 'Sam Scudder', 'Pied Piper': 'Thomas Peterson'}

print(super_villains['Fiddler'])

print(super_villains.values())

some_guy = 'Fred11'

first_names = []
first_names.append(some_guy)
print(some_guy, ';', first_names)
some_guy = 'preBill'
print(some_guy, ';', first_names)
another_list_of_names = first_names
another_list_of_names.append('George')
some_guy = 'Bill'

print (some_guy, ';', first_names, ';', another_list_of_names)

def testFunc(someobj):
    print("In testFunc")
    print(someobj)
    someobj = 'testFunc Bill'
    print(someobj)

testFunc(some_guy)
testFunc(another_list_of_names)


print (some_guy, ';', first_names, ';', another_list_of_names)

age = 31
if not(age == 30):
    print("Not 30")
elif age == 30:
    print("30")


def f123():
    yield 1
    yield 2
    yield 3
    for x in range(9,15):
        yield x

for item in f123():
    print(item)

test_file = open("SampleText.txt")
for line in test_file:
    print(line, end="")

print("DoSomething")

def doSomething(a,b,c):
    a = 34
    print(a)
    print(b)
    b = 999.99
    print(b)
    c.insert(1,3333)

c = [1,2,4,5,6,5,8]
a = 12
b = -123.2
print(a)
print(b)
print(c)
doSomething(a,b,c)
print(a)
print(b)
print(c)

