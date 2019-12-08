# TODO: 模仿run_batch.改进:1. 加入多次运行取平均.2. cycle与-t -a的关系要分别作图.
import os
import matplotlib.pyplot as plt
import numpy as np 
from multiprocessing.dummy import Pool as ThreadPool 
all_rate = {}
all_rate_asso_rela = {}
def run_once(arg):
    tot_size_w,ass_w = arg
    cmd = "../cachesim-64 ../microbench-test.log.bz2 -t {} -a {} 2>&1".format(tot_size_w,ass_w)
    if tot_size_w > ass_w + 6:
        try:
            ops = np.mean([[eval(i) for i in os.popen(cmd)][0] for _ in range(3)])
            if ass_w not in all_rate.keys():
                all_rate[ass_w] = [[],[]]
            if tot_size_w not in all_rate_asso_rela.keys():
                all_rate_asso_rela[tot_size_w] = [[],[]]
            all_rate[ass_w][0].append(tot_size_w)
            all_rate[ass_w][1].append(ops)
            all_rate_asso_rela[tot_size_w][0].append(ass_w)
            all_rate_asso_rela[tot_size_w][1].append(ops)

        except:
            print(ops)
            pass

def fmt_and_show(mod = 0):
    if mod==0:
        plt.xlabel("Total size width")  
        plt.legend(loc="lower right")
        plt.title("Relation between cache size and hit rate")  
    else: 
        plt.xlabel("Associativity width")
        plt.legend(loc="upper left")
        plt.title("Relation between associativity width and hit rate")

    plt.ylabel("Cache hit rate") 
    plt.show()

args = [(i,j) for i in range(6,30) for j in range(8)]
# args = [(i,j) for i in range(6,8) for j in range(2)]

pool = ThreadPool(8)

pool.map(run_once,args)
pool.close() 
pool.join() 
        
print(all_rate)
print(all_rate_asso_rela)

for j,i in enumerate(sorted(list(all_rate.keys()))):
    plt.scatter(all_rate[i][0],all_rate[i][1],label = "associativity width {}".format(i))
    if ((j+1)%4==0):
        fmt_and_show()
fmt_and_show()
for j,i in enumerate(sorted(list(all_rate_asso_rela.keys()))):
    plt.scatter(all_rate_asso_rela[i][0],all_rate_asso_rela[i][1],label = "total size width {}".format(i))
    if ((j+1)%8==0):
        fmt_and_show(1)
fmt_and_show(1)
