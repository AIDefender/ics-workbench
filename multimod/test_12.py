#! /usr/bin/python3
import os
ops=[i.split() for i in os.popen("./multimod-64 -i 1 1 1 1")]
for i in ops:
    try:
        i=[eval(j) for j in i]
        # print(i)
        assert ((i[0]*i[1])%i[2])==i[3], "Wrong implementation!:{}*{}%{}={}".format(i[0],i[1],i[2],i[3])
    except IndexError:
        pass 
    except SyntaxError:
        pass 
ops=[i.split() for i in os.popen("./multimod-64 -i 2 1 1 1")]
for i in ops:
    try:
        i=[eval(j) for j in i]
        assert ((i[0]*i[1])%i[2])==i[3], "Wrong implementation!"
    except IndexError:
        pass 
    except SyntaxError:
        pass 
print("All Test OK!")