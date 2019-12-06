import os
import matplotlib.pyplot as plt
# all_tot_size_w = []
# all_ass_w = []
all_rate = {}
for tot_size_w in range(6,20):
    for ass_w in range(0,8):
        cmd = "./cachesim-64 microbench-test.log.bz2 -t {} -a {} 2>&1".format(tot_size_w,ass_w)
        try:
            ops=[eval(i) for i in os.popen(cmd)][0]
            # all_tot_size_w.append(tot_size_w)
            # all_ass_w.append(ass_w)
            # all_rate.append(ops)
            if ass_w not in all_rate.keys():
                all_rate[ass_w] = [[],[]]
            all_rate[ass_w][0].append(tot_size_w)
            all_rate[ass_w][1].append(ops)
        except:
            # ops=[i for i in os.popen(cmd)]
            # print(ops)
            pass
for j,i in enumerate(list(all_rate.keys())):
    plt.scatter(all_rate[i][0],all_rate[i][1])
    if (j%4==0):
        plt.show()
# print(all_rate)