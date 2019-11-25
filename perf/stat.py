import pandas as pd
import matplotlib.pyplot as plt 
# from scipy.stats import norm
# import numpy as np 
data = pd.read_csv("./res",header=None)
data.columns = ["Time(ms)"]
print(data.describe())
plt.plot(data)
plt.title("Performance analysis")
plt.xlabel("Index")
plt.ylabel("Running Time(ms)")
plt.show()