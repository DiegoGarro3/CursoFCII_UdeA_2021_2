#!/usr/bin/env python
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

os.system( 'g++ main_circular.cpp xy2D.cpp')
os.system('./a.out')

data=pd.read_csv("Circular_salida.csv",low_memory=False)

T=pd.DataFrame([data["XPOS"],data["YPOS"]])
DF=pd.DataFrame.transpose(T)
plt.plot(DF["XPOS"],DF["YPOS"])
plt.title("Movimiento Circular")
plt.xlabel("X(m)")
plt.ylabel("Y(m)")
plt.grid()
plt.show()
