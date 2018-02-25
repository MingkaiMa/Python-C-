
import time

class A(object):
    def __init__(self,x):
        self._x = x

    def foo1(self, str):
        print(self._x)
        print(str)
        return self._x
        #time.sleep(1)

    def f(self):
        print(self._x)
        print(id(self._x))
        time.sleep(1)

    def foo2(self):
        print(self._x)

def show():
    print('haha')

def print_arg(s):
    print('here')
    print(s)

def use_fun_in_class_1(a):
    c = A(a)
    print("wawawa")
    #print(a)
    c.f()

def use_fun_in_class(a):
    a.f()


def addition(a,b):
    print('a =', a)
    print('b =', b)
    show()
    B = A(333330)
    B.f()

    L = [A(i) for i in range(3)]
    for i in L:

        use_fun_in_class(i)


    return a + b

if __name__ == "__main__":
    addition(1,2)