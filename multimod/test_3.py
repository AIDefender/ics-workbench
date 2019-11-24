#! /usr/bin/env python3
import os 
import random
def gen_rand(max):
    return random.randint(0,int(max))
def get_double(value):
    return eval(os.popen("./get_double {}".format(value)).readlines()[0])

def test1():
    for i in range(10000):
        a,b = gen_rand(2**26.5-1),gen_rand(2**26.5-1)
        m=gen_rand(2**63-1)

        res = os.popen("./multimod-64 -i 3 {} {} {}".format(a,b,m)).readlines()
        res = eval(res[0])
        assert res==a*b%m

    print("All tests OK.")

def test2():
    less_count=0
    less_right=0
    more_count=0
    more_right=0
    equal_count=0
    equal_right=0
    for i in range(10000):
        a, b, m = gen_rand(2**63-1), gen_rand(2**63-1), gen_rand(2**63-1)
        res = os.popen("./multimod-64 -i 3 {} {} {}".format(a,b,m)).readlines()
        res = eval(res[0])
        c_double = get_double(a*b)
        if c_double<a*b:
            less_count+=1
            if res==a*b%m:
                less_right+=1
        elif c_double>a*b:
            # print(c_double,a*b,c_double-a*b)
            # print(c_double//m-a*b//m)
            more_count+=1
            if res==a*b%m:
                more_right+=1
        else:
            equal_count+=1
            if res==a*b%m:
                equal_right+=1

    print(less_count,less_right,more_count,more_right,equal_count,equal_right)

def main():
    print("Testing a*b<=2**53-1.......")
    test1()
    print("Testing without restrict:")
    test2()

if __name__ == "__main__":
    main()