#! /usr/bin/env python
# :vim:et ai sw=4 ts=4 sts=4 :
import sys

class Geometry():
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.trail = []
        self.add_current()

    def add_current(self):
        self.trail.append((self.x,self.y))

    def up(self, count = 1):
        for _ in range(count):
            self.y -= 1
            self.add_current()

    def down(self, count = 1):
        for _ in range(count):
            self.y += 1
            self.add_current()

    def left(self, count = 1):
        for _ in range(count):
            self.x -= 1
            self.add_current()

    def right(self, count = 1):
        for _ in range(count):
            self.x -= 1
            self.add_current()

    def format(self, name):
        print "static gridlocation %s[%d] =" % (name, len(self.trail))
        print "{"
        print "\t",
        for x,y in self.trail:
            print "{ %d, %d }, " % (x , y) ,
        print
        print "};"

def chris_v1():
    string0 = Geometry(5,0)
    string0.down(7)
    for _ in range(2):
        string0.left()
        string0.up(7)
        string0.left()
        string0.down(7)
    string0.left()
    string0.up(7)
    string0.format("string0")

    string1 = Geometry(6,0)
    string1.down(13)
    for _ in range(3):
        string1.left()
        string1.up(5)
        string1.left()
        string1.down(5)
    string1.format("string1")

    string2 = Geometry(7,0)
    string2.down(13)
    for _ in range(3):
        string2.right()
        string2.up(5)
        string2.right()
        string2.down(5)
    string2.format("string2")

    string3 = Geometry(8,0)
    string3.down(7)
    for _ in range(2):
        string3.right()
        string3.up(7)
        string3.right()
        string3.down(7)
    string3.right()
    string3.up(7)
    string3.format("string3")


if __name__ == "__main__":
    chris_v1()
