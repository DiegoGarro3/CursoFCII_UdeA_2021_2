#!/usr/bin/env python
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

os.system( 'g++ main.cpp path_Integral.cpp')
os.system('./a.out')

data=pd.read_csv("wave_salida.csv",low_memory=False)

T=pd.DataFrame([data["XPOS"],data["PSI2"]])
DF=pd.DataFrame.transpose(T)
plt.plot(7.65*DF["XPOS"],9271243.634**2*DF["PSI2"]/max(DF["PSI2"]))
plt.xlim(-3.5*10**-14,3.5*10**-14)
plt.title("Estado fundamental")
plt.xlabel("X")
plt.ylabel("$|\psi_0|^2$")
plt.grid()
plt.show()
