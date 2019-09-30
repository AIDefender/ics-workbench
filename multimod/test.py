#! /usr/bin/python3
import os
ops=[i.split() for i in os.popen("./multimod-64 -i 1 1 1 1")]
for i in ops:
    try:
        i=[eval(j) for j in i]
        if ((i[0]*i[1])%i[2])!=i[3]:
            print(i)
        else:
            print("Good expression!")
    except :
        pass 