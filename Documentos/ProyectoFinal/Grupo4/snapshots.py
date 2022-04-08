from readline import append_history_file
import matplotlib.pyplot as plt
import numpy as np


datos1=np.loadtxt("spin.dat")




x1=[x for x in datos1 ]

spin1=np.array(x1)

SPIN1=np.reshape(spin1,(100,100))


plt.imshow(SPIN1,"seismic")
plt.title("T=5")
plt.show()

