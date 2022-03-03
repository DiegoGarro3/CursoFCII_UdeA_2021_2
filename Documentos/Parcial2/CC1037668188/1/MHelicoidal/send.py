#!/usr/bin/env python
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from mpl_toolkits.mplot3d import axes3d

os.system( 'g++ ../MCircular/xy2D.cpp xyz3D.cpp main_Helicoidal.cpp' )
os.system('./a.out')

data=pd.read_csv("Helicoidal_salida.cvs",low_memory=False)

T=pd.DataFrame([data["XPOS"],data["YPOS"],data["ZPOS"]])
DF=pd.DataFrame.transpose(T)

fig = plt.figure(figsize = (8,8))
ax = fig.add_subplot(111,projection='3d')
ax.plot(data["XPOS"], data["YPOS"], data["ZPOS"],color="r")
plt.title("Movimiento Helicoidal",size=17)
plt.xlabel("$X(m)$",size=14)
plt.ylabel("$Y(m)$",size=14)
ax.set_zlabel("$Z(m)$",size=14)
plt.grid()
plt.show()

