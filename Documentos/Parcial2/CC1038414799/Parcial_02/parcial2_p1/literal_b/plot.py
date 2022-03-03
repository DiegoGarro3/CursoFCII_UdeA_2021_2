import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np


#reading data file
datos = np.loadtxt("motion_3D.dat", skiprows=1)


#Extracting x,y,z columns
x=[x[1] for x in datos]
y=[x[2] for x in datos]
z=[x[3] for x in datos]


#plots 3d movement
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.set_title('Sprial')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.plot(x, y, z)

#Saves plot
plt.savefig("spiral_image.png")





