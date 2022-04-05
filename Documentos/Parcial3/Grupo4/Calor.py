from readline import append_history_file
import matplotlib.pyplot as plt
import numpy as np


datos=np.loadtxt("datos.txt",skiprows=1)

x=[x[2] for x in datos ]
y=[x[3] for x in datos ]
z=[x[4] for x in datos ]

Tuple=[]
for i in range(len(x)):
    T=[]
    T.append(x[i])
    T.append(y[i])
    Tuple.append(T)

#print(Tuple)


#plt.pcolormesh(Tuple,z)
#plt.show()



zz=np.array(z)

x=np.unique(x)
y=np.unique(y)
X,Y=np.meshgrid(x,y)
Z=zz.reshape(len(x),len(y))
print(Z)




plt.pcolormesh(Y,X,Z)
plt.colorbar()
plt.title("Distributionheat of a plate")

plt.show()