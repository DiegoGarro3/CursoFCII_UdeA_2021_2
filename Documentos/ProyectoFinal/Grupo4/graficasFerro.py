from readline import append_history_file
import matplotlib.pyplot as plt
import numpy as np


datos=np.loadtxt("Ferromagnetismo0.dat")
datos2=np.loadtxt("Ferromagnetismo1.dat")


x=[x[0] for x in datos ]
y=[x[1] for x in datos ]

x2=[x[0] for x in datos2 ]
y2=[x[1] for x in datos2 ]

plt.plot(x,y,"o")
plt.plot(x2,y2,"o")
plt.grid()
plt.show()
