import pandas as pd
import matplotlib.pyplot as plt 
from scipy.stats import shapiro,kstest
import numpy as np 
import sys  
func_name = sys.argv[1]
data = pd.read_csv("./res",header=None)
data.columns = ["Time(ms)"]
print(data.describe())
with open("./res","r") as f:
    res = np.loadtxt(f,dtype = float)
data_mu = np.mean(res)
data_std = np.std(res)
time_count = []
cnt_interval = 100
for interval in np.linspace(data_mu-3*data_std,data_mu+3*data_std,cnt_interval):
    count = 0
    for i in res:
        if interval <= i < interval + 6*data_std/cnt_interval:
            count+=1
    time_count.append(count)


print("p value of Shapiro-Wilk test:",shapiro(time_count)[1])
print("p value of kstest:",kstest(time_count,'norm')[1])
plt.bar(list(range(cnt_interval)),time_count)
plt.title("Running time distribution of "+func_name)
plt.xlabel("Counts")
plt.ylabel("Index")
plt.show()





plt.plot(data)
plt.title("Performance analysis of "+func_name)
plt.xlabel("Index")
plt.ylabel("Running Time(ms)")
plt.show()

try:
    with open("./num_1","r") as f:
        num_1 = np.loadtxt(f,dtype = int,delimiter=",")
except FileNotFoundError:
    quit()
with open("./res","r") as f:
    res = np.loadtxt(f,dtype = float)
with open("./hi_1","r") as f:
    hi_1 = np.loadtxt(f,dtype = int,delimiter=",")

a_num_1 = {}
b_num_1 = {}
c_num_1 = {}
assert num_1.shape[0] == res.shape[0]
for i in range(num_1.shape[0]):
    for j,k in enumerate([a_num_1,b_num_1,c_num_1]):
        if num_1[i,j] not in k.keys():
            k[num_1[i,j]] = []
        k[num_1[i,j]].append(res[i])
    
for k in [a_num_1,b_num_1,c_num_1]:
    for (i,j) in zip(k.keys(),k.values()):
        k[i] = np.mean(j)

# print(a_num_1)
plt.scatter(list(a_num_1.keys()),list(a_num_1.values()),label = "num of binary 1 in a")
plt.scatter(list(b_num_1.keys()),list(b_num_1.values()),label = "num of binary 1 in b")
plt.scatter(list(c_num_1.keys()),list(c_num_1.values()),label = "num of binary 1 in m")
plt.legend(loc="lower right")
plt.title("Running time and num of binary 1@ "+func_name)
plt.xlabel("num of 1")
plt.ylabel("Running time")
plt.show()


a_hi_1 = {}
b_hi_1 = {}
c_hi_1 = {}
assert hi_1.shape[0] == res.shape[0]
for i in range(hi_1.shape[0]):
    for j,k in enumerate([a_hi_1,b_hi_1,c_hi_1]):
        if hi_1[i,j] not in k.keys():
            k[hi_1[i,j]] = []
        k[hi_1[i,j]].append(res[i])
    
for k in [a_hi_1,b_hi_1,c_hi_1]:
    for (i,j) in zip(k.keys(),k.values()):
        k[i] = np.mean(j)

# print(a_hi_1)
plt.scatter(list(a_hi_1.keys()),list(a_hi_1.values()),label = "hi of binary 1 in a")
plt.scatter(list(b_hi_1.keys()),list(b_hi_1.values()),label = "hi of binary 1 in b")
plt.scatter(list(c_hi_1.keys()),list(c_hi_1.values()),label = "hi of binary 1 in m")
plt.legend(loc="lower right")
plt.title("Running time and hi of binary 1@ "+func_name)
plt.xlabel("hi of 1")
plt.ylabel("Running time")
plt.show()