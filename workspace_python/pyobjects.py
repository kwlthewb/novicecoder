import random
import sys
import os

class Animal:
    __name = ""
    __height = 0
    __weight = 0
    __sound = 0
    def __init__(self, n, h, w, s):
        self.__name = n
        self.__height = h
        self.__weight = w
        self.__sound = s
    def set_name(self,name):
        self.__name = name;
    def get_name(self):
        return self.__name
    def get_height(self):
        return self.__height
    def get_weight(self):
        return self.__weight
    def get_sound(self):
        return self.__sound
    def toString(self):
        return "{} is {} cm tall {} kilo and says {}".format(self.__name,
                                                             self.__height,
                                                             self.__weight,
                                                             self.__sound)

class Cat(Animal):
    __color = ""
    __food = ""
    __house = ""
    def __init__(self,n,h,w,s,c,f,house):
        self.__color = c
        self.__food = f
        self.__house = house
        super(Cat,self).__init__(n,h,w,s)

    def toString(self):
        return Animal.toString(self) + " is {} likes to eat {} lives in {}".format(self.__color,
                                                             self.__food,
                                                             self.__house)

    def multiple_sounds(self, how_loud, how_many=None):
        if how_many is None:
            print(self.get_sound())
        else:
            print(self.get_sound() * how_many)
        print(how_loud)

cat = Animal("Whisker", 30, 13, 'meow')
cat2 = Cat("WhiskerII", 30, 13, 'meow meow', 'white','tuna','1361 83rd street')
print(cat.toString())
print(cat2.toString())
cat3 = Cat("Bugger", 44, 234, 'cough..cough', 'black-purple-pink','ribeye steak','8115 23th ave')
print(cat2.toString())
print(cat3.toString())
cat3.multiple_sounds(999, 3)